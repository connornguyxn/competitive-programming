var l,r,x,y,cnt:longint;
    pw2,pw:qword;
///////////////////////////////////////
begin
readln(l,r);
pw2 := 1;
for x := 0 to 30 do
    begin
    pw := pw2;
    for y := 0 to 19 do
        begin
        if (pw > r) then
            break;
        if (pw >= l) then
            cnt := cnt + 1;
        pw := pw * 3;
        end;
    pw2 := pw2 * 2;
    end;
writeln(cnt);
end.