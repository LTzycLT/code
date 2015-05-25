javac a.java
javac b.java
javac data.java

flag=1
while (( $flag==1 ))
do
java data>data.in
java a<data.in>a.out
java b<data.in>b.out
diff a.out b.out > res
if [ -s res ] 
then
flag=2
fi
done
