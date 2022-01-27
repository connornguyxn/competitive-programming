var a,bak:array[1..100] of longint;
    res:ansistring = ''; 
    c,n,i,j,d,test,tests,u:longint;
    valid:boolean;
///////////////////////////////////////
function stri(a:longint):ansistring;
    begin
    str(a,stri);
    end;
///////////////////////////////////////
function ucln(a,b:longint):longint;
var r:longint;
    begin
    while (b <> 0) do
        begin
        r := a mod b;
        a := b;
        b := r;
        end;
    ucln := a;
    end;
///////////////////////////////////////
begin
assign(input,'ntu_smaca.inp');reset(input);
readln(n,tests);
for i := 1 to n do
    read(a[i]);
bak := a;
for test := 1 to tests do
    begin
    valid := true;
    for i := 1 to n do
        begin
        read(c);
        if (not valid) then
            continue;
        valid := false;
        //write('with c = ',c,' ');
        for j := 1 to n do
            begin
            u := ucln(c,a[j]);
            c := c div u;
            a[j] := a[j] div u;
            if (a[j] mod c = 0) then
                begin
                a[j] := a[j] div c;
                valid := true;
                break;
                end;
            end;
        //writeln(valid);
        end;
    if (valid) then
        begin
        d := d + 1;
        res := res + stri(test) + ' ';
        end;
    a := bak;
    end;
writeln(d);
writeln(res);
end.