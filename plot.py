
import matplotlib.pyplot as plt

font_title = {
    'family' : 'serif',
    'color'  : 'blue',
    'size'   : 20
}

font_label = {
    'family' : 'serif',
    'color'  : 'darkred',
    'size'   : 15
}


with open("result") as f:
    lines = f.readlines()
    
x = [ float(line.split(':')[0]) for line in lines ]
y = [ float(line.split(':')[1]) for line in lines ]
plt.plot(x, y)

plt.title("Modello Preda-Predatore", fontdict=font_title, loc = "left")
plt.xlabel("Conigli", fontdict=font_label)
plt.ylabel("Lupi", fontdict=font_label)

plt.show()

