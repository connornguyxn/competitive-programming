var a,kq:ansistring;
    c,k:longint;
///////////////////////////////////////
function stri(a:longint):ansistring;
    /////////////////
    begin
    str(a,stri);
    end;
///////////////////////////////////////
begin
assign(input,'xoaxaulonnhat.inp');reset(input);
readln(a);
readln(k);
while (k <> 0) do
    begin
    //writeln('k := ',k);
    for c := 9 downto 0 do
        begin
        //writeln('with c := ',c);
        if ((pos(stri(c),a) > 0) and (length(a) - pos(stri(c),a) + 1 >= k)) then
            begin
            kq := kq + stri(c);
            //writeln('pos := ',pos(stri(c),a));
            delete(a,1,pos(stri(c),a));
            //writeln('a := ',a);
            k := k - 1;
            break;
            end;
        end;
    end;
writeln(kq);
end.