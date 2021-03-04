defmodule ProcessTesterTest do
  use ExUnit.Case
  doctest ProcessTester

  test "greets the world" do
    assert ProcessTester.hello() == :world
  end
end
