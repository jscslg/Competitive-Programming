import sys
import os
file=sys.argv[1:]
dname=" ".join(file)
if dname[-3:].lower()=="cpp":
    print(">>>> BUILDING ")
    os.system("g++ "+dname+" -o exec -DLOCAL_JUDGE")
    print(">>>> EXECUTING ")
    os.system("./exec")

elif dname[-2:].lower()=="py":
    fname=dname.split("/")[-1]
    com=""
    sdir=dname.split("/")
    for x in sdir[:-1]:
        if " " in x:
            com=com+'"'+x+'"'+"/"
        else:
            com=com+x+"/"
    print(">>>> RUNNING ")
    os.system("python3 "+com+fname[:-2]+"py")

else:
    print(">>>> NOT ADDED THESE TYPES OF FILES")