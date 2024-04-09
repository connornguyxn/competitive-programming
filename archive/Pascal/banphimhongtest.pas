var a:array[1..9] of string=('.','abc','def','ghi','jkl','mno','pqrs','tuw','wxyz');
b:array[1..9] of string;
n,i,i1,i2:longint;
x,prt,i11:string;
c:char;

begin
assign(input,'mobiphone.inp');reset(input);
assign(output,'mobiphone.out');rewrite(output);
for i:=1 to 9 do
    begin
    readln(n);
    b[i]:=a[n];
    end;
readln(x);
//for i:=1 to 9 do write(b[i],' ');
for i:=1 to length(x) do
    begin
    c:=x[i];
    writeln(c);

    end;
//delete(prt,length(prt),1);
//writeln();
end.