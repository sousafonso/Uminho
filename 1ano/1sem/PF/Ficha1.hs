perimetro :: Double -> Double
perimetro x = 2 * pi * x

dist :: (Double, Double) -> (Double, Double) -> Double
dist (x1,y1) (x2, y2) = sqrt((x1-x2)^2 + (y1-y2)^2)

primUlt :: [a] -> (a,a)
primUlt lista = (head lista, last lista)

multiplo :: Int -> Int -> Bool
multiplo m n | mod m n == 0

truncaImpar :: [a] -> [a]
truncaImpar lista = if not (multiplo (length lista) 2)
                    then tail lista
                    else lista

max2 :: Int -> Int -> Int
max2 a b = if a > b
           then a
           else b