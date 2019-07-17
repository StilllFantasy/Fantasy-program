import numpy as np
import matplotlib.pyplot as plt
import pandas as pd
from sklearn.model_selection import train_test_split

fruit_df = pd.read_csv("Python/ML/Day2/fruits.txt")
fruit_df.head(n=4)