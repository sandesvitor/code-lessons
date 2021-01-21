# "bread"

hints = "flour, water, yeast, bakery"
IO.puts "Hints: #{hints}"

guess = IO.gets "Guess the word: "
guess = String.strip(guess)
# IO.inspect String.strip(guess) # not for production!

case guess do
  "bread" ->
    IO.puts "won!"
   _->
    IO.puts "lost!"
end
