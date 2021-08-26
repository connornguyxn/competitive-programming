var a:array[1..9] of string=('.','abc','def','ghi','jkl','mno','pqrs','tuv','wxyz');
b:array[1..9] of string;
n,i,j,j2:longint;
x,prt,js:string;
c:char;

begin
assign(input,'mobiphone.inp');reset(input);
assign(output,'mobiphone.out');rewrite(output);
prt:='';
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
    for j:=1 to 9 do
        begin
        if pos(c,b[j])<>0 then
            begin
            for j2:=1 to pos(c,b[j]) do
                begin
                str(j,js);
                //writeln(j);
                prt:=prt+js;
                //writeln(prt);
                end;
            prt:=prt+'#';
            end;
            break;
        end;
    end;
delete(prt,length(prt),1);
writeln(prt);
end.
