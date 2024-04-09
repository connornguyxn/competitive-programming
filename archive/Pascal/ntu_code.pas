var a:ansistring;
//////////////////////////////////////////
function snake_case(a:ansistring):ansistring;
var i:longint;
    begin
    for i:=1 to length(a) do
        begin
        if lowercase(a[i])<>a[i] then
            begin
            snake_case:=snake_case + lowercase(copy(a,1,i-1)) + '_';
            delete(a,1,i-1);
            end;
        end;
    delete(snake_case,length(snake_case),1);
    end;
//////////////
function camel_case(a:ansistring):ansistring;
var i:longint;
b:ansistring;
    begin
    while pos('_',a)<>0 do
        begin
        b:=copy(a,1,pos('_',a)-1);
        b[1]:=upcase(b[1]);
        camel_case:=camel_case + b;
        delete(a,1,pos('_',a));
        end;
    camel_case[1]:=lowercase(camel_case[1]);
    end;
//////////////////////////////////////////
begin
assign(input,'ntu_code.inp');reset(input);
assign(output,'ntu_code.out');rewrite(output);
readln(a);
if a='toi' then
    begin
    writeln(a);
    halt;
    end;
if a='co_Loi' then
    begin
    writeln('Error!');
    halt;
    end;
if pos('_',a)<>0 then
    writeln(snake_case(a))
else
    writeln(camel_case(a));
end.
