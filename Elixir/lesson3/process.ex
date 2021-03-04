defmodule ProcessIntro do
  def greeter() do
    receive do
      _ ->
        IO.puts("Hello Friend!")
    end
    greeter()
  end

  def counter() do
    receive do
      value ->
        IO.puts(value)
        Process.sleep(500)
        send(self(), value + 1)
    end

    counter()
  end
end
