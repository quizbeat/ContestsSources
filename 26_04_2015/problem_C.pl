#!/usr/bin/perl
$\ = "\n";
sub func {
	my $s = shift;
	my $a = int ((sqrt(1+8*$s)-1)/2);
	my $n = $s - ($a+1)*$a/2;
	my $r = "";
	$r = func($n) if $n != 0;
	"(". $r .")". "()" x ($a-1) ;
}
my $a = <>;
print func $a;
