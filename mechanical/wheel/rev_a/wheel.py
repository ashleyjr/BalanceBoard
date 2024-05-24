import Part
import math
from FreeCAD import Base
import Draft

# Run in Freecad
# exec(open(<path_to_file>,'r').read())

LEN_AXLE    = 5
LEN_HUB     = 5
LEN_RIM     = 5
LEN_SPOKE   = 2

WID_SPOKE   = 2

RAD_AXLE    = 0.5
RAD_HUB     = 2
RAD_RIM_IN  = 10
RAD_RIM_OUT = 12

NUM_SPOKES  = 9

# Name
name = "wheel"

# Create new document
if len(App.listDocuments()) != 0:
    for doc in App.listDocuments():
        App.setActiveDocument(doc)
        App.closeDocument(doc)
App.newDocument(name)
App.setActiveDocument(name)
App.ActiveDocument=App.getDocument(name)
Gui.ActiveDocument=Gui.getDocument(name)

# Axle
axle = Part.makeCylinder(
    RAD_AXLE,
    LEN_AXLE)

# Hub
hub = Part.makeCylinder(
    RAD_HUB,
    LEN_HUB)
hub=hub.cut(axle)

# Rim
rim = Part.makeCylinder(
    RAD_RIM_OUT,
    LEN_RIM)
rim_in = Part.makeCylinder(
    RAD_RIM_IN,
    LEN_RIM)
rim=rim.cut(rim_in)

# Spoke
spoke = Part.makeBox(RAD_RIM_IN,LEN_SPOKE,WID_SPOKE)
x = RAD_AXLE
y = -WID_SPOKE / 2
z = (LEN_HUB / 2) - (LEN_SPOKE / 2)
spoke.translate(Base.Vector(x,y,z))
for _ in range(NUM_SPOKES):
    Part.show(spoke)
    spoke.rotate(Base.Vector(0,0,0),Base.Vector(0,0,1),(360/NUM_SPOKES))

Part.show(hub)
Part.show(rim)

