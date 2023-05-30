# ![icon](https://github.com/sxfour/SFMLStarWars/assets/112577182/687545bf-3155-4d0d-9a89-7bf236690239) SFMLStarWars
# Первая из моих игр с использованием библиотеки SFML и ООП на C++ #1

https://github.com/sxfour/SFMLStarWars/assets/112577182/cd81db62-2647-470d-82f3-59ebfd04d228

* Все текстуры в Images, оба врага используют Follow Player из разницы координат игрока и врага.
* Верхняя панель сердечек использует переменную для счёта и переключает на другую (в случае поражение игрока).
* Background parallax

# Эффект движения заднего фона (background parallax)
* Для достижение данного эффекта, я решил использовать базовый шейдер через загрузку в память SFML
  т.к использование двух фонов одновременно и смена их по координатам приводила к появлению полос.
  
![tempsnip](https://github.com/sxfour/SFMLStarWars/assets/112577182/a0445b55-991f-4d0f-a0d5-3dacf1a2efcf)

# Анимация персонажей
* Создано через простое условие в основном цикле программы.
* Смена происходит каждую секунду - через специальную переменную подсчёта псевдоигрового времени.

![изображение](https://github.com/sxfour/SFMLStarWars/assets/112577182/87a683fb-497d-410f-b073-ccc9c59177b3)

# Изменение скорости врагов, зайти -> Moves.cpp
![изображение](https://github.com/sxfour/SFMLStarWars/assets/112577182/26a53b3a-f6ab-487d-acc9-d6c1bd246b50)

# P.S Это мой первый ООП на C++ поэтому он может быть ошибочным...
