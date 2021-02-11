import pyautogui

#Obtenemos el tamaño de la pantalla 
width, height = pyautogui.size()
print(width)
print(height)
#Obtenemos la posicion actual del mouse
x, y = pyautogui.position()
#Imprimimos la posicion actual del mouse
print(x)
print(y)
#Movemos el cursor a una cordenada especifica
pyautogui.moveTo(100,100,duration=0.25)

#Movemos el cursor 100 pixelesa la derecha
pyautogui.moveRel(100,0,duration=0.25)
#Movemos el cursor 100 pixelesa la izquiera
pyautogui.moveRel(-100,0,duration=0.25)
#Movemos el cursor 100 pixeles abajo
pyautogui.moveRel(0,100,duration=0.25)
#Movemos el cursor 100 pixeles arriba
pyautogui.moveRel(0,-100,duration=0.25)
#Obtenemos la posicion actual del mouse
x, y = pyautogui.position()
#Imprimimos la posicion actual del mouse
print(x)
print(y)
#Realizamos un click
pyautogui.click()
