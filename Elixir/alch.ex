defmodule Alch do
  def hello_friend(message) do
    message # in Elixir a function return the last instruction
  end
  def read_my_file(filename) do
    File.read(filename)
  end
  def mapping(%{"key" => value}) do
    IO.puts value
  end
end
