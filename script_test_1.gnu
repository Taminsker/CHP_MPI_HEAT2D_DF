reset
xmax = 10
xmin = 0.00000
ymax = 10
ymin = 0.00000
dx = 0.1
dy = 1

sp [xmin-dx:xmax+dx][ymin-dy:ymax+dy] 'test1.dat' t '#Solution numérique 0' w p palette
pause 0.0001
pause -1
