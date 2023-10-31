uses crt;
var a,b,m,n,ucln,bcnn:int64;


begin
clrscr;
readln(a,b);
m := a;
n := b;
//t:=a mod b;
  while a <> b do
     if a > b then a := a -b
     else b := b- a;
ucln:=a;
bcnn:=m * n div ucln;
writeln(bcnn,ucln);
readln
end.
