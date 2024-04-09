const nmod = 1000000007;
var n:int64;
///////////////////////////////////////
function pow(a,n:int64):int64;
    var k,h:int64;
    /////////////////
    begin
    if (n = 1) then
        exit(a);
    k := n div 2;
    h := a mod nmod * a mod nmod;
    if (n mod 2 = 0) then
        exit(pow(h,k) mod nmod)
    else 
        exit((pow(h,k) * a mod nmod) mod nmod);
    end;
///////////////////////////////////////
begin
//assign(input,'PP3.inp');reset(input);
//assign(output,'PP3.out');rewrite(output);
readln(n);
writeln(pow(3,n - 1) mod nmod);
end.