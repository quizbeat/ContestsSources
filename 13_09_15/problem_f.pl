#!/usr/bin/perl
use bigint;
my($a, $b) = split " ", <>;
my $p = 1;
for my $n (0..1000) {
	if (($a eq $b && $p eq $a) || $p =~ m/^$a.*?$b$/) {
		print $n, "\n";
		exit;
	}
	$p <<= 1;
}
print "-1\n";
