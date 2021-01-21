input = "HELLO@GMAIL.com,Hello@gmail.com,OLA@GKAFKFA.com"

input
  |> String.downcase()
  |> String.split(",")
  |> Enum.uniq()
  |> List.first()
  |> IO.puts()
