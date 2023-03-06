import my_extension
import numpy as np

image = np.zeros((1, 5), dtype=np.uint8)
image[0, 1] = 1
image[0, 3] = 3
result = my_extension.interact(image)
