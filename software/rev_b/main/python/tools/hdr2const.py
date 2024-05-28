class hdr2Const():
    DEFINE = "#define"
    def __init__(self, filename):
        # Open file
        with open(filename, "r") as r:
            lines = r.read()

        # Find all tags
        defines = []
        for line in lines.split("\n"):
            if self.DEFINE in line:
                defines.append(line)

        # Remove tag
        for i in range(len(defines)):
            # Remove tag
            defines[i] = defines[i].split(self.DEFINE)
            assert(len(defines[i]) == 2)
            defines[i] = defines[i][1]

        # Split in to name and value
        for i in range(len(defines)):
            defines[i] = defines[i].split(" ")
            def_const = []
            for c in defines[i]:
                if(len(c) > 0):
                    def_const.append(c)
            defines[i] = def_const

        # Create varaibles/value for all pairs
        for define in defines:
            if len(define) == 2:
                if define[1][0:2] == "0x":
                    setattr(self, define[0], int(define[1][2:],16))
                else:
                    setattr(self, define[0], int(define[1]))
