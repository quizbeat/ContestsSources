#!/usr/bin/perl
my %h = (paper => 0, scissors => 1, rock => 2);
my $n = <>;
my $A = <>;
my $B = <>;
chomp $A;
chomp $B;
my @A = split " ", $A;
my @B = split " ", $B;
my ($ac, $bc) = (0, 0);
for (my $i = 0; $i < $n; ++$i) {
	my ($a, $b) = ($A[$i], $B[$i]);
	if ($a eq "paper" && $b eq "rock") {
		++$ac;
	}
	elsif ($b eq "paper" && $a eq "rock") {
		++$bc;
	}
	elsif ($h{$a} > $h{$b}) {
		++$ac;
	}
	elsif ($h{$a} < $h{$b}) {
		++$bc;
	}
}
print "$ac $bc\n";

