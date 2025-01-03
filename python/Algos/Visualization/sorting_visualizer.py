import tkinter
from PIL import Image, ImageTk

__WINDOW_H__ = 400
__WINDOW_W__ = 400
print(__WINDOW_W__//3//10)
root = tkinter.Tk()
root.title("Sorting Algo Visualizer")
root.geometry(f"{__WINDOW_H__}x{__WINDOW_W__}")
img = Image.open("sort_icon.png")
ico = ImageTk.PhotoImage(img)
root.wm_iconphoto(False, ico)
root.configure(bg="black")
sort_btn = tkinter.Button(master=root, text="Sort Array", width=__WINDOW_W__//3//10)
sort_btn.pack()
canvas = tkinter.Canvas(master=root, height=int(__WINDOW_H__*0.9), background="lightblue", )
canvas.pack()
root.mainloop()