from matplotlib import pyplot as plt
import numpy as np


def plot_points(files, func, save=False):
    for file in files:
        with open(file, 'r') as f:
            points = f.read().split('\n')[:-1]
        for count, point in enumerate(points):
            p = np.array(list(map(float, point.split())))
            least, great = p.min(), p.max()
            great = great * 1.1 if great > 0 else great * 0.9
            least = least * 0.9 if least > 0 else least * 1.1
            space = np.linspace(least, great, 100)
            plt.figure()
            plt.plot(space, func(space))
            plt.plot(space, [0 for _ in range(len(space))])
            plt.scatter(p, func(p))
            plt.grid(True)
            plt.title(file.split('.txt')[0] + "; x" + str(count))
            if save == True:
                plt.savefig("plots\\" + file.split('.txt')[0]  + "; x" + str(count))
            else:
                plt.show()


def plot_multy_point(file, save=False):

    with open(file, 'r') as f:
        all_points = f.read().split('\n')[:-1]
    for count, points in enumerate(all_points):
        all_x = np.array([])
        all_y = np.array([])
        x_y = points.split(' ')[:-1]
        for point in x_y:
            x, y = tuple(map(float, point.split(';')))
            all_x = np.append(all_x, x)
            all_y = np.append(all_y, y)
        
        least, great = all_x.min(), all_x.max()
        great = great * 1.1 if great > 0 else great * 0.9
        least = least * 0.9 if least > 0 else least * 1.1
        plt.figure()
        plt.scatter(all_x, all_y)
        plt.grid()
        plt.title('system iterations; x' + str(count))
        if save == True:
            plt.savefig("plots\\" + "system iterations"  + "; x" + str(count))
        else:
            plt.show()


def f1(x):
    return x**4 - 4*x**3 - 8*x**2 + 1


def f2(x):
    return x**x + 9*x - 20


f_1_files = ['f1 chords.txt', 'f1 iterations.txt', 'f1 newton.txt']
f_2_files = ['f2 chords.txt', 'f2 iterations.txt', 'f2 newton.txt']
system = 'system iterations.txt'


plot_points(f_1_files, f1, True)
plot_points(f_2_files, f2, True)
plot_multy_point(system, True)

