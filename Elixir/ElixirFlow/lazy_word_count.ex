File.stream!("./file.txt")
|> Enum.flat_map(&String.split(&1, " "))
|> Enum.reduce(%{}, fn word, acc ->
    Map.update(acc, word, 1, & &1 + 1)
end)
|> Enum.to_list()
|> IO.inspect
