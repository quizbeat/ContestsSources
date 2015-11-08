#!/usr/bin/perl
my $s = <>;
chomp $s;
while ($s =~ s/\(\)//) {}
my $n = length($s);
$s =~ s/\)//g;
my $rn = length($s);
print $n - 2*$rn;
