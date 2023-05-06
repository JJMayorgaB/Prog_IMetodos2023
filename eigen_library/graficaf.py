import matplotlib.pyplot as plt
import numpy as np

plt.rc('text', usetex=True)
plt.rc('font', family='serif')

m1, f1, f2  = np.loadtxt("stats.txt", unpack=True)

fig, ax = plt.subplots()

ax.plot(m1, f1, color='red', label=r"$y=f_{1}(m_{1})$")
ax.plot(m1, f2, color='blue', label=r"$y=f_{2}(m_{1})$")

ax.set_xlabel(r"\boldmath{$x$}", fontsize=16)
ax.set_ylabel(r'\boldmath{$y$}', fontsize=16)
ax.set_title(r'\textbf{Estimación numerica de las funciones pdf} \boldmath{$f(x)$} \textbf{y cdf} \boldmath{$F(x)$} \textbf{de la distribución beta para} \boldmath{$\alpha$} \textbf{= 2.0 y} \boldmath{$\beta$} \textbf{= 5.0}', x=0.5, y=1, fontsize=15)

ax.legend(framealpha=1, shadow=True, fontsize=14, edgecolor="k",borderaxespad=1, borderpad=0.75)
ax.set_xscale('log')
ax.set_yscale('log')
ax.grid(True, which='minor', linestyle="-.", alpha=0.5)
ax.grid(True, linestyle="-", alpha=1)
ax.minorticks_on()
ax.tick_params(which="both", width="1.5")
ax.tick_params(which="minor", length=4, direction="in")
ax.tick_params(which="major", length=12, direction="inout")
#ax.set_xlim(0, 0.9 )
#ax.set_ylim(0, 2.6)
#ax.set_xticks([0.000, 0.005, 0.010, 0.015, 0.020, 0.025, 0.030])
#ax.set_xticklabels(["0", "0.005", "0.010", "0.015", "0.020", "0.025", "0.030"])
ax.spines['top'].set_linewidth(1.5)
ax.spines['bottom'].set_linewidth(1.5)
ax.spines['left'].set_linewidth(1.5)
ax.spines['right'].set_linewidth(1.5)

plt.show()

fig.savefig("stats.pdf",bbox_inches='tight')