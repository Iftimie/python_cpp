import my_extension
import numpy as np
import pickle

image = np.zeros((1, 5), dtype=np.uint8)
metadata = my_extension.interact(image)
metadata = pickle.loads(pickle.dumps(metadata))
print("metadata unpicked", metadata)
print("image", image)