defmodule Count do
  def start do
    Agent.start(fn -> 0 end, name: __MODULE__)
  end

  def get do
    Agent.get(__MODULE__, fn state -> state end)
  end

  def add do
    Agent.update(__MODULE__, fn state -> state + 1 end)
  end
end
