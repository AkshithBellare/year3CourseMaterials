from PIL import Image
import numpy as np

f = open("KittenRGB.txt", "r")

file_data = f.read()
file_pixel_data = file_data.split(' ')

ln = len(file_pixel_data)

for i in range(ln-1):
    file_pixel_data[i] = int(file_pixel_data[i])

grayscale = []
yiq = []
pixels = []
for i in range(0, ln-1, 3):
    rgb = file_pixel_data[i:i+3]
    pixels.append(tuple(rgb))
    gs = rgb[0]*0.21 + rgb[1]*0.72 + rgb[2]*0.07
    grayscale.append(gs)
    y = rgb[0]*0.299 + rgb[1]*0.587 + rgb[2]*0.114
    i = rgb[0]*0.596 - rgb[1]*0.275 - rgb[2]*0.321
    q = rgb[0]*0.212 - rgb[1]*0.523 + rgb[2]*0.311
    yiq.append(y)
    yiq.append(i)
    yiq.append(q)

array = np.array(pixels, dtype=np.uint8)

new_image = Image.fromarray(array)
new_image.save('kit.jfif')