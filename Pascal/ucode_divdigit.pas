var i,t3,t7,tru,test,tests:longint;
    a,c7:ansistring;
    d:array[1..9] of longint;
///////////////////////////////////////
function inte(a:ansistring):longint;
    begin
    val(a,inte);
    end;
///////////////////////////////////////
begin
assign(input,'ucode_divdigit.inp');reset(input);
readln(tests);
for test := 1 to tests do
    begin
    readln(a);
    t7 := 0;
    t3 := 0;
    tru := 0;
    c7 := '';
    fillchar(d,sizeof(d),0);
    for i := length(a) downto 1 do
        begin
        d[inte(a[i])] := d[inte(a[i])] + 1;
        t3 := t3 + inte(a[i]);
        if (length(c7) = 3) then
            begin
            if (tru = 1) then
                t7 := t7 - inte(c7)
            else
                t7 := t7 + inte(c7);
            tru := 1 - tru;
            c7 := a[i];
            end
        else
            c7 := a[i] + c7;
        end;
    if (tru = 1) then
        t7 := t7 - inte(c7)
    else
        t7 := t7 + inte(c7);
    if (inte(a[length(a)]) mod 2 = 0) then
        d[1] := d[1] + d[2];
    if (t3 mod 3 = 0) then
        d[1] := d[1] + d[3];
    if (inte(copy(a,length(a) - 1,2)) mod 4 = 0) then
        d[1] := d[1] + d[4];
    if (inte(a[length(a)]) mod 5 = 0) then
        d[1] := d[1] + d[5];
    if ((inte(a[length(a)]) mod 2 = 0) and (t3 mod 3 = 0)) then
        d[1] := d[1] + d[6];
    if (t7 mod 7 = 0) then
        d[1] := d[1] + d[7];
    if (inte(copy(a,length(a) - 2,3)) mod 8 = 0) then
        d[1] := d[1] + d[8];
    if (t3 mod 9 = 0) then
        d[1] := d[1] + d[9];
    writeln(d[1]);
    end;
end.