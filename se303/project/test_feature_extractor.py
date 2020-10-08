from struct import unpack


marker_mapping = {
   0xffc0: "Start of Frame 0",
   0xffc1: "Start of Frame 1",
   0xffc2: "Start of Frame 2",
   0xffc3: "Start of Frame 3",
   0xffc4: "DHT",
   0xffc5: "SOF5 (Start of Frame 5)",
   0xffc6: "SOF6 (Start of Frame 6)",
   0xffc7: "SOF7 (Start of Frame 7)",
   0xffc8: "JPG",
   0xffc9: "SOF9 (Start of Frame 9)",
   0xffca: "SOF10 (Start of Frame 10)",
   0xffcb: "SOF11 (Start of Frame 11)",
   0xffcc: "DAC (Define Arithmetic Coding)",
   0xffcd: "SOF13",
   0xffce: "SOF14",
   0xffcf: "SOF15",
   0xffd0: "RST0",
   0xffd1: "RST1",
   0xffd2: "RST2",
   0xffd3: "RST3",
   0xffd4: "RST4",
   0xffd5: "RST5",
   0xffd6: "RST6",
   0xffd7: "RST7",
   0xffd8: "SOI",
   0xffd9: "EOI",
   0xffda: "SOS",
   0xffdb: "DQT",
   0xffdc: "DNL",
   0xffdd: "DRI",
   0xffde: "DHP",
   0xffdf: "EXP",
   0xffe0: "APP0",
   0xffe1: "APP1",
   0xffe2: "APP2",
   0xffe3: "APP3",
   0xffe4: "APP4",
   0xffe5: "APP5",
   0xffe6: "APP6",
   0xffe7: "APP7",
   0xffe8: "APP8",
   0xffe9: "APP9",
   0xffea: "APP10",
   0xffeb: "APP11",
   0xffec: "APP12",
   0xffed: "APP13",
   0xffee: "APP14",
   0xffef: "APP15",
   0xfff0: "JPG0",
   0xfff1: "JPG1",
   0xfff2: "JPG2",
   0xfff3: "JPG3",
   0xfff4: "JPG4",
   0xfff5: "JPG5",
   0xfff6: "JPG6",
   0xfff7: "JPG7",
   0xfff8: "JPG8",
   0xfff9: "JPG9",
   0xfffa: "JPG10",
   0xfffb: "JPG11",
   0xfffc: "JPG12",
   0xfffd: "JPG13",
   0xfffe: "COM",
}


class JPEG:
    def __init__(self, image_file):
        with open(image_file, 'rb') as f:
            self.img_data = f.read()
    
    def decode(self):
        data = self.img_data
        marker_DQT_num = 0
        marker_DQT_size_max = 0
        marker_DHT_num = 0
        marker_DHT_size_max = 0
        file_markers_num = 0
        marker_EOI_content_after_num = 0
        marker_APP12_size_max = 0
        marker_APP1_size_max = 0
        marker_COM_size_max = 0
        file_size = len(data)
        print(type(data))
        #print(file_size)
        while(True):
            marker, = unpack(">H", data[0:2])
            marker_map = marker_mapping.get(marker)
            if marker_map != None:
                file_markers_num += 1
                print(marker_map)
                if marker_map == "DQT":
                    marker_DQT_num += 1
                    lenchunk, = unpack(">H", data[2:4])
                    if lenchunk > marker_DQT_size_max:
                        marker_DQT_size_max = lenchunk
                    data = data[2+lenchunk:]
                elif marker_map == "DHT":
                    marker_DHT_num += 1
                    lenchunk, = unpack(">H", data[2:4])
                    if lenchunk > marker_DHT_size_max:
                        marker_DHT_size_max = lenchunk
                    data = data[2+lenchunk]
                elif marker_map == "EOI":
                    if len(data[2:]) > marker_EOI_content_after_num:
                        marker_EOI_content_after_num = len(data[2:])
                    data = data[2:]
                elif marker_map == "SOS":
                    data = data[2:]
                elif marker_map == "APP12":
                    lenchunk, = unpack(">H", data[2:4])
                    if lenchunk > marker_APP12_size_max:
                        marker_APP12_size_max = lenchunk
                    data = data[2+lenchunk:]
                elif marker_map == "APP1":
                    lenchunk, = unpack(">H", data[2:4])
                    if lenchunk > marker_APP1_size_max:
                        marker_APP1_size_max = lenchunk
                    data = data[2+lenchunk:]
                elif marker_map == "COM":
                    lenchunk, = unpack(">H", data[2:4])
                    if lenchunk > marker_COM_size_max:
                        marker_COM_size_max = lenchunk
                    data = data[2+lenchunk:]
                else:
                    data = data[2:]
            else:
                data = data[1:]
            if (type(data) == "int"):
                print(marker_DQT_num)
                print(marker_DHT_num)
                print(file_markers_num)
                print(marker_EOI_content_after_num)
                print(marker_DQT_size_max)
                print(marker_DHT_size_max)
                print(file_size)
                print(marker_COM_size_max)
                print(marker_APP1_size_max)
                print(marker_APP12_size_max)
                break
          #  marker, = unpack(">H", data[0:2])
          #  print(marker_mapping.get(marker))
          #  print(hex(marker))
          #  if marker == 0xffd8:
          #      data = data[2:]
          #  elif marker == 0xffd9:
          #      return
          #  elif marker == 0xffda:
          #      data = data[-2:]
          #  else:
          #      lenchunk, = unpack(">H", data[2:4])
          #      data = data[2+lenchunk:]            
          #  if len(data)==0:
          #      break        

if __name__ == "__main__":
    img = JPEG('test.jpg')
    img.decode()    

# OUTPUT:
# Start of Image
# Application Default Header
# Quantization Table
# Quantization Table
# Start of Frame
# Huffman Table
# Huffman Table
# Huffman Table
# Huffman Table
# Start of Scan
# End of Image