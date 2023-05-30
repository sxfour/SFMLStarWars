# ![icon](https://github.com/sxfour/SFMLStarWars/assets/112577182/687545bf-3155-4d0d-9a89-7bf236690239) SFMLStarWars
# Первая из моих игр с использованием библиотеки SFML и ООП на C++ #1

https://github.com/sxfour/SFMLStarWars/assets/112577182/cd81db62-2647-470d-82f3-59ebfd04d228

* Все текстуры в Images, оба врага используют Follow Player из разницы координат игрока и врага.
* Верхняя панель сердечек использует переменную для счёта и переключает на другую (в случае поражение игрока).
![panel1](https://github.com/sxfour/SFMLStarWars/assets/112577182/404bf21c-5bea-44b6-a5fd-537a00f5b60e)

* Background parallax.
* Простая анимация персонажей.
![player1](https://github.com/sxfour/SFMLStarWars/assets/112577182/5222066f-e875-4bc5-92db-4beb691b96ce)
![enemy1](https://github.com/sxfour/SFMLStarWars/assets/112577182/76aa8622-f72f-4b53-b522-e29709c8d2b7)
![enemy2](https://github.com/sxfour/SFMLStarWars/assets/112577182/4ed232a4-36e2-49c9-b785-e6dbfff12f7f)

# Эффект движения заднего фона (background parallax)
* Для достижение данного эффекта, я решил использовать базовый шейдер через загрузку в память SFML
  т.к использование двух фонов одновременно и смена их по координатам приводила к появлению полос.
  
![tempsnip](https://github.com/sxfour/SFMLStarWars/assets/112577182/a0445b55-991f-4d0f-a0d5-3dacf1a2efcf)

# Анимация персонажей
* Создано через простое условие в основном цикле программы.
* Смена происходит каждую секунду - через специальную переменную подсчёта псевдоигрового времени.

![изображение](https://github.com/sxfour/SFMLStarWars/assets/112577182/87a683fb-497d-410f-b073-ccc9c59177b3)

* frameTimer конвертируем offset заднего фона * 15 и % 2 получаем на выходе 0 или 1 каждую секунду (чётность)

![изображение](https://github.com/sxfour/SFMLStarWars/assets/112577182/62026f44-3d5c-4253-88f9-8eb83d374aa6)

# Изменение скорости врагов, зайти -> Moves.cpp
![изображение](https://github.com/sxfour/SFMLStarWars/assets/112577182/26a53b3a-f6ab-487d-acc9-d6c1bd246b50)

# Движение врагов в сторону игрока (follow player)
* Для реализации этого действия, достаточно вычислить разницу координат между игроком и врагом, задав скорость движения.

![изображение](https://github.com/sxfour/SFMLStarWars/assets/112577182/610f296e-dad8-4863-9342-dde80d26d356)

# P.S Это мой первый ООП на C++ поэтому он может быть ошибочным...
