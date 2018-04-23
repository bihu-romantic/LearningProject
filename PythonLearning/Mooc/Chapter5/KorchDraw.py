#！/usr/bin/env python3
import turtle

def korch(size, n):
    if n == 0:
        turtle.fd(size)
    else:
        for angle in [0, 60, -120, 60]:
            turtle.left(angle)
            korch(size/3, n-1)
def main():
    turtle.setup(600,600)
    turtle.penup()
    turtle.goto(-200, 30)
    turtle.pendown()
    turtle.pensize(2)
    level = 2
    korch(100, level)
    turtle.right(120)
    korch(100,level)
    turtle.right(120)
    korch(100,level)
    turtle.hideturtle()
    turtle.done()

main()