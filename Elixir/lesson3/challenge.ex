defmodule Challenge do
  use Agent

  def controller do
    receive do
      :start ->
        cpid = spawn(fn -> counter() end)
        send cpid, 0
        Agent.start_link(fn -> cpid end, name: __MODULE__)
      :stop ->
        cpid = Agent.get(__MODULE__, & &1)
        Process.exit(cpid, :ok)
    end
    controller()
  end

  def counter() do
    receive do
      value ->
        IO.puts(value)
        Process.sleep(2500)
        send(self(), value + 1)
    end
    counter()
  end
end
