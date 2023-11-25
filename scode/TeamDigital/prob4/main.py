import turtle

ball = turtle.Turtle()

ball.forward(100)
ball.left(45)
ball.pensize(5)
ball.color("dark salmon")
ball.forward(50)
ball.right(90)
ball.penup()
ball.forward(100)
ball.right(135)
ball.pensize(10)
ball.color("light green")
ball.pendown()
ball.forward(200)
ball.shape("circle")

turtle.done()