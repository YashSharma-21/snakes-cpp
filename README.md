# Moving Snakes (C++)
<p>
  This moving snakes program is written in C++ and requires an environment which has access to the graphics.h header file. The TurboC++ environment is recommended to run this program.
  This program's code uses the path string "C:\\TurboC3\\BGI" to the initgraph() function so make sure that you've installed the turboC++ IDE in this path.
</p>

<p>
  A class named as "snake" has been defined to allow the creation of snake instances. In its current state, the program creates two snake instances that move around on the canvas. Each snake tries to examine a list of all available eggs on the canvas and then picks the nearest egg to itself and then moves towards it. After eating an egg, a snake will grow in length by 1 unit.
</p>
