                                    
def mathFunction()
    loop do
    input = gets.chomp
    if input.match?(/\D/)
        puts "Invalid input. Try again!"

    elsif input.match?(/\A\d+\z/)
        x = input.to_i
        if x > 3
            puts "Write a number under 4!"
            next
        else
            puts "Well done. Here is your number:", x
            return
        end
        end
    end
end

puts "Please input a number under 4: "
mathFunction
