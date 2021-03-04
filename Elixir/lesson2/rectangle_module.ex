defmodule Rectangle do
  def area_loop do
    receive do
      {:area, w, h} ->
      IO.puts("Area = #{w * h}")
      area_loop()
      {:pmeter, w, h} ->
      IO.puts("pmeter = #{w + h}")
      area_loop()
    end

  end

  def counter() do
    receive do
      value ->
        IO.puts(value)
        Process.sleep(2000)
        send(self(), value + 1)
    end
    counter()
  end
end
