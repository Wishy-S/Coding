add=($1);
n=($2);
for i in range{1,n};
do
cp ~/Desktop/Coding/templates/normal.cpp add|mv normal.cpp ($i).cpp;
done;

