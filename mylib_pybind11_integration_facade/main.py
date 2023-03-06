import my_extension
import numpy as np
import pickle

def metadata_to_str(metadata):
    packets_str = ','.join([ f'{{"data": {p.data}, value: {p.value}}}' for p in metadata.packets])
    return f'{{"packets": {packets_str}}}'

image = np.zeros((1, 5), dtype=np.uint8)
image[0, 1] = 1
image[0, 3] = 3
result = my_extension.interact(image)
result = pickle.loads(pickle.dumps(result))
print("result unpicked", metadata_to_str(result[0]),  metadata_to_str(result[1]))
print("Image:", image)
