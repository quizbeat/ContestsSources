#!/usr/bin/perl
my %h = (
		a => "a",
		b => "bac",
		c => "cad",
		e => "e",
		f => "feg",
		g => "geh",
		h => "hij",
		i => "i",
		j => "jik",
		k => "kil",
		l => "lim",
		m => "mon",
		n => "nop",
		o => "o",
		p => "poq",
		q => "qor",
		r => "ros",
		s => "sut",
		t => "tuv",
		u => "u",
		v => "vuw",
		w => "wux",
		x => "xuy",
		y => "yuz",
		z => "zuz");
my $a = <>;
chomp $a;
my $res = "";
for my $i (split "", $a) {
	$res .= $h{$i};
}
print $res, "\n";