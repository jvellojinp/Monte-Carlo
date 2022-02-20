######################################################################################
#
#                            Random numbers from an arbitrary distribution
#                                       Jose I. Vellojin P.
#                                      jvellojinp@unal.edu.co
######################################################################################

######################################################################################
#  Instructions:
# 1. Replace f(x) in line 45 by any function you want your random numbers to come from
# (that is, this function will define the distribution).
# 2. In line 49 write your function in proper LateX syntax for it to display in the
# title of the plot.
# 3. Compile.
#
# ***  Check that the normalization is indeed 1 (the normalization constant will be displayed
# in the terminal after compiling). If this isn't the case our distribution will be
# ill defined.
######################################################################################

from scipy.stats import binom
import numpy as np
import matplotlib as mpl
import matplotlib.pyplot as plt
import random as rn
from scipy.stats import poisson
from math import comb

######################################################################################
# Initial parameters.
######################################################################################

K = 50  # Number of possible outcomes
N = 100  # Number of trials
norm = 0
sum = 0
normcheck = 0
pmf = []
cdf = []
fnorm = []
histogram = []

######################################################################################
# Initialize the function (only positive) and get its norm to make it a proper probability distribution.
######################################################################################


def f(x):
    return x**3


f_name = "$x^3$"


for i in range(K):
    norm = norm + f(i)

for i in range(K):
    fnorm.append(0)

for i in range(K):
    fnorm[i] = f(i)/norm

######################################################################################
# Initialize and construct probability mass function (pmf) and cumulative density
# function (cdf) with the distribution function.
######################################################################################

for i in range(K):
    pmf.append(0)

for i in range(K):
    cdf.append(0)

for i in range(K):
    pmf[i] = fnorm[i]

for i in range(K):
    sum = sum + pmf[i]
    cdf[i] = sum

######################################################################################
# Initialize and construct a histogram with the Monte Carlo method.
######################################################################################

for i in range(K):
    histogram.append(0)

for i in range(N):
    r = rn.uniform(0, 1)
    for j in range(1, K):
        if r >= cdf[j-1] and r < cdf[j]:
            bingo = j
            break
    histogram[bingo] += 1

######################################################################################
# Check that our distribution function function is indeed normalized.
######################################################################################

for i in range(K):
    normcheck = normcheck + fnorm[i]

print("Normalization constant =", sum)

######################################################################################
# Plot histogram.
######################################################################################

plt.figure(figsize=(12, 7))
x = np.arange(0, len(histogram), 1)
plt.xlabel("Steps", alpha=1, fontsize='20', color='black')
plt.ylabel("Frequency", alpha=1,  fontsize='20', color='black')
plt.title('Histogram with $N$ = {} trials and $K$ = {} possible outcomes for a {}-distribution'.format(N, K, f_name))
plt.plot(x, histogram, ds='steps-mid', alpha=1,
         color='black', linewidth=2, label="Simulation")
plt.plot(x, N*f(x)/norm, color='#00008B', linewidth=2, alpha=1, label="Theory")
plt.xlim(0, K)
plt.grid(b=True, color="#999999", linestyle="-", alpha=1)
plt.minorticks_on()
plt.tick_params(bottom=True, top=True, right=True, direction='in',
                size=5, which='both', labelsize='15', color='black')
plt.legend(fontsize=15)
plt.show()
