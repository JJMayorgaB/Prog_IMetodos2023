import matplotlib.pyplot as plt
import numpy as np

plt.rc('text', usetex=True)
plt.rc('font', family='serif')

m1, f1, f2  = np.loadtxt("stats.txt", unpack=True)

fig, ax = plt.subplots()

ax.plot(m1, f1, color='red', label=r"$y=\lambda_{1}(m_{1})$")
ax.plot(m1, f2, color='blue', label=r"$y=\lambda_{2}(m_{1})$")

ax.set_xlabel(r"\boldmath{$m_{1}$} \boldmath{$[kg]$}", fontsize=16)
ax.set_ylabel(r'\textbf{Valor Propio} \boldmath{$\lambda$}', fontsize=16)
ax.set_title(r'\textbf{Valores Propios} \boldmath{$\lambda_{1},$} \boldmath{$\lambda_{1}$} \textbf{del sistema de resortes acoplados en función de la masa} \boldmath{$m_{1}$}', x=0.5, y=1, fontsize=15)

ax.legend(framealpha=1, shadow=True, fontsize=14, edgecolor="k",borderaxespad=1, borderpad=0.75)
ax.set_xscale('log')
ax.set_yscale('log')
ax.grid(True, which='minor', linestyle="-.", alpha=0.5)
ax.grid(True, linestyle="-", alpha=1)
ax.minorticks_on()
ax.tick_params(which="both", width="1.5")
ax.tick_params(which="minor", length=4, direction="in")
ax.tick_params(which="major", length=12, direction="inout")
ax.set_xlim(1, 800 )
#ax.set_ylim(0, 2.6)
#ax.set_xticks([0.000, 0.005, 0.010, 0.015, 0.020, 0.025, 0.030])
#ax.set_xticklabels(["0", "0.005", "0.010", "0.015", "0.020", "0.025", "0.030"])
ax.spines['top'].set_linewidth(1.5)
ax.spines['bottom'].set_linewidth(1.5)
ax.spines['left'].set_linewidth(1.5)
ax.spines['right'].set_linewidth(1.5)

plt.show()

fig.savefig("stats.pdf",bbox_inches='tight')