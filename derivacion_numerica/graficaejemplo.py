import matplotlib as plt
import numpy as np

x = np.linspace(0, 10, 100)
y1 = np.sin(x)
y2 = np.cos(x)

fig, ax = plt.subplots()

ax.plot(x, y1, label='Seno')
ax.plot(x, y2, label='Coseno')

ax.set_xlabel('x')
ax.set_ylabel('y')
ax.set_title('Gráficas de Seno y Coseno')

ax.legend()

plt.show()



