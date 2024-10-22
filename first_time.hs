-- File: first_try.hs
import Text.Read (readMaybe)
main :: IO()
main = do
    putStrLn "Enter first number: "
    input1 <- getLine
    putStrLn "Enter second number: "
    input2 <- getLine

    let intsum1 = readMaybe input1 :: Maybe Int
    let intsum2 = readMaybe input2 :: Maybe Int
    do
        case (intsum1, intsum2) of
            (Just num1, Just num2) -> do
                print(num1 + num2)
