% dbalpha.bib
%
% A BibTeX style for XML bibliography output.
% An extension of BibTeX standard bibliography style `alpha'.
%
% version 0.1
%
% Sylvain Schmitz <schmitz@i3s.unice.fr>
% Copyright (c) Laboratoire I3S -- http://www.i3s.unice.fr
%
% Permission is hereby granted, free of charge, to any person obtaining a copy
% of this software and associated documentation files (the "Software"), to
% deal in the Software without restriction, including without limitation the
% rights to use, copy, modify, merge, publish, distribute, sublicense, and/or
% sell copies of the Software, and to permit persons to whom the Software is
% furnished to do so, subject to the following conditions:
%
% The above copyright notice and this permission notice shall be included in
% all copies or substantial portions of the Software.
%
% THE SOFTWARE IS PROVIDED "AS IS", WITHOUT WARRANTY OF ANY KIND, EXPRESS OR
% IMPLIED, INCLUDING BUT NOT LIMITED TO THE WARRANTIES OF MERCHANTABILITY,
% FITNESS FOR A PARTICULAR PURPOSE AND NONINFRINGEMENT. IN NO EVENT SHALL
% THE AUTHOR BE LIABLE FOR ANY CLAIM, DAMAGES OR OTHER LIABILITY, WHETHER IN
% AN ACTION OF CONTRACT, TORT OR OTHERWISE, ARISING FROM, OUT OF OR IN
% CONNECTION WITH THE SOFTWARE OR THE USE OR OTHER DEALINGS IN THE SOFTWARE.

ENTRY
  { address
    author
    booktitle
    chapter
    doi
    edition
    editor
    url
    howpublished
    institution
    journal
    key
    month
    note
    number
    organization
    pages
    publisher
    school
    series
    title
    type
    volume
    year
  }
  {}
  { label extra.label sort.label }

INTEGERS { indent.level lvl }

FUNCTION {init.level}
{ #0 'indent.level :=
}

STRINGS { s t }

FUNCTION {output.nonnull}
{ indent.level 'lvl :=
  { lvl #0 > }
    { "  " write$
      lvl #1 - 'lvl :=
    }
  while$
  write$
  newline$
}

FUNCTION {output}
{ duplicate$ empty$
    'pop$
    'output.nonnull
  if$
}

FUNCTION {output.check}
{ 't :=
  duplicate$ empty$
    { pop$ "empty " t * " in " * cite$ * warning$ }
    'output.nonnull
  if$
}

FUNCTION {bibentry.begin}
{ newline$
  "<biblioentry role=''" swap$ * "'' id=''" * cite$ * "''>" * output
  indent.level #1 + 'indent.level :=
  "<abbrev id=''" cite$ * ".abbrev''>" * label * "</abbrev>" * output
}

FUNCTION {bibentry.end}
{ indent.level #1 - 'indent.level :=
  "</biblioentry>" output
}


FUNCTION {biblioset.begin}
{ "<biblioset role=''" swap$ * "''>" * output
  indent.level #1 + 'indent.level :=
}

FUNCTION {biblioset.end}
{ indent.level #1 - 'indent.level :=
  "</biblioset>" output
}

FUNCTION {not}
{   { #0 }
    { #1 }
  if$
}

FUNCTION {and}
{   'skip$
    { pop$ #0 }
  if$
}

FUNCTION {or}
{   { pop$ #1 }
    'skip$
  if$
}

FUNCTION {field.or.null}
{ duplicate$ empty$
    { pop$ "" }
    'skip$
  if$
}

INTEGERS { nameptr namesleft numnames }

FUNCTION {format.names}
{ 's :=
  't :=
  #1 'nameptr :=
  s num.names$ 'numnames :=
  numnames 'namesleft :=
  numnames #1 >
    { "<authorgroup>"
      indent.level #1 + 'indent.level :=
      "<" * t * ">" *
    }
    { "<" t * ">" *
    }
  if$

  { namesleft #0 > }
    { "<authorname>" * "<firstname>" * s nameptr "{ff}{ jj}" format.name$ * "</firstname>" *
      "<surname>" * s nameptr "{vv~}{ll}" format.name$ * "</surname>" * "</authorname>" *
      "</" * t * ">" *
      namesleft #1 >
        { "<" * t * ">" * }
        'skip$
      if$
      nameptr #1 + 'nameptr :=
      namesleft #1 - 'namesleft :=
    }
  while$

  numnames #1 >
    { indent.level #1 - 'indent.level :=
      "</authorgroup>" *
    }
    'skip$
  if$
}

FUNCTION {format.authors}
{ author empty$
    { "" }
    { "author" author format.names }
  if$
}

FUNCTION {format.editors}
{ editor empty$
    { "" }
    { "editor" editor format.names }
  if$
}

FUNCTION {format.title}
{ title empty$
    { "" }
    { "<title>" title "t" change.case$ * "</title>" * }
  if$
}

FUNCTION {format.btitle}
{ "<title>" title * "</title>" *
}

FUNCTION {format.jtitle}
{ "<title>" journal * "</title>" *
}

FUNCTION {format.booktitle}
{ booktitle empty$
    { "" }
    { "<title>" booktitle * "</title>" * }
  if$
}

FUNCTION {format.url}
{ url empty$
    { "" }
    { "<bibliosource class=''uri''>" url * "</bibliosource>" * }
  if$
}

FUNCTION {format.doi}
{ doi empty$
    { "" }
    { "<bibliosource class=''doi''>" doi * "</bibliosource>" * }
  if$
}

FUNCTION {format.note}
{ note empty$
    { "" }
    { "<bibliomisc role=''note''>" note * "</bibliomisc>" * }
  if$
}

FUNCTION {format.howpublished}
{ note empty$
    { "" }
    { "<bibliomisc role=''howpublished''>" howpublished * "</bibliomisc>" * }
  if$
}

FUNCTION {format.type}
{ "<bibliomisc role=''type''>"
  swap$
  type empty$
    'skip$
    { pop$
      type "t" change.case$
    }
  if$ *
  "</bibliomisc>" *
}

FUNCTION {format.tr.number}
{ "<bibliomisc role=''type''>"
  type empty$
    { "Technical Report" }
    { type }
  if$
  number empty$
    { "t" change.case$ * }
    { * number * }
  if$
  "</bibliomisc>" *
}

FUNCTION {format.chapter}
{ chapter empty$
    { "" }
    { "<bibliomisc role=''>"
      type empty$
	{ "chapter" *  }
	{ type "l" change.case$ * }
      if$
      "''>" * chapter * "</bibliomisc>" *
    }
  if$
}

FUNCTION {format.publisher}
{ publisher empty$
    { "" }
    { "<publisher><publishername>" publisher * "</publishername></publisher>" * }
  if$
}

FUNCTION {format.address}
{ address empty$
    { "" }
    { "<address>" address * "</address>" * }
  if$
}

FUNCTION {format.organization}
{ organization empty$
    { "" }
    { "<orgname>" organization * "</orgname>" * }
  if$
}

FUNCTION {format.institution}
{ institution empty$
    { "" }
    { "<orgname>" institution * "</orgname>" * }
  if$
}

FUNCTION {format.school}
{ school empty$
    { "" }
    { "<orgname>" school * "</orgname>" * }
  if$
}

FUNCTION {format.date}
{ year empty$
    { month empty$
	{ "" }
	{ "there's a month but no year in " cite$ * warning$
	  "<pubdate>" month * "</pubdate>" *
	}
      if$
    }
    { month empty$
	{ "<pubdate>" year * "</pubdate>" * }
	{ "<pubdate>" month * " " * year * "</pubdate>" * }
      if$
    }
  if$
}

FUNCTION {either.or.check}
{ empty$
    'pop$
    { "can't use both " swap$ * " fields in " * cite$ * warning$ }
  if$
}

FUNCTION {format.bvolume}
{ volume empty$
    { "" }
    { series empty$
	{ "<volumenum>" volume * "</volumenum>" * }
	{ "<subtitle role=''series''>" series * "</subtitle>" * 
          "<seriesvolnum>" * volume * "</seriesvolnum>" *
        }
      if$
      "volume and number" number either.or.check
    }
  if$
}

FUNCTION {format.number.series}
{ volume empty$
    { number empty$
	{ series empty$
            { "" }
            { "<subtitle role=''series''>" series * "</subtitle>" * }
          if$
        }
	{ "<seriesvolnum>" number * "</seriesvolnum>" *
	  series empty$
	    { "there's a number but no series in " cite$ * warning$ }
	    { " in " * series * }
	  if$
	}
      if$
    }
    { "" }
  if$
}

FUNCTION {format.edition}
{ edition empty$
    { "" }
    { "<edition>" edition * "</edition>" * }
  if$
}

INTEGERS { multiresult }

FUNCTION {multi.page.check}
{ 't :=
  #0 'multiresult :=
    { multiresult not
      t empty$ not
      and
    }
    { t #1 #1 substring$
      duplicate$ "-" =
      swap$ duplicate$ "," =
      swap$ "+" =
      or or
	{ #1 'multiresult := }
	{ t #2 global.max$ substring$ 't := }
      if$
    }
  while$
  multiresult
}

FUNCTION {n.dashify}
{ 't :=
  ""
    { t empty$ not }
    { t #1 #1 substring$ "-" =
	{ t #1 #2 substring$ "--" = not
	    { "--" *
	      t #2 global.max$ substring$ 't :=
	    }
	    {   { t #1 #1 substring$ "-" = }
		{ "-" *
		  t #2 global.max$ substring$ 't :=
		}
	      while$
	    }
	  if$
	}
	{ t #1 #1 substring$ *
	  t #2 global.max$ substring$ 't :=
	}
      if$
    }
  while$
}

FUNCTION {format.pages}
{ pages empty$
    { "" }
    { pages multi.page.check
	{ "<pagenums>" pages n.dashify * "</pagenums>" * }
	{ "<pagenums>" pages * "</pagenums>" * }
      if$
    }
  if$
}

FUNCTION {format.vol.num}
{ volume empty$
    'skip$
    { "<volumenum>" volume * "</volumenum>" * }
  if$

  number empty$
    'skip$
    { "<issuenum>" number * "</issuenum>" *
      volume empty$
	{ "there's a number but no volume in " cite$ * warning$ }
	{ * }
      if$
    }
  if$
}

FUNCTION {format.conf}
{ "<confgroup>"
  booktitle empty$
    'skip$
    { "<conftitle>" * booktitle * "</conftitle>" * }
  if$
  format.address *
  organization empty$
    'skip$
    { "<confsponsor>" * organization * "</confsponsor>" * }
  if$
  "</confgroup>" *
} 


FUNCTION {empty.misc.check}
{ author empty$ title empty$ howpublished empty$
  month empty$ year empty$ note empty$
  and and and and and
  key empty$ not and
    { "all relevant fields are empty in " cite$ * warning$ }
    'skip$
  if$
}

FUNCTION {format.article.crossref}
{ key empty$
    { journal empty$
	{ "need key or journal for " cite$ * " to crossref " * crossref *
	  warning$
	  ""
	}
	{ format.jtitle * }
      if$
    }
    { key * }
  if$
%  " \cite{" * crossref * "}" *
}

FUNCTION {format.book.crossref}
{ volume empty$
    { "empty volume in " cite$ * "'s crossref of " * crossref * warning$
    }
    { format.bvolume *
    }
  if$
  editor empty$
  editor field.or.null author field.or.null =
  or
    { key empty$
	{ series empty$
	    { "need editor, key, or series for " cite$ * " to crossref " *
	      crossref * warning$
	      "" *
	    }
	    { format.number.series * }
	  if$
	}
	{ key * }
      if$
    }
    { format.editors * }
  if$
%  " \cite{" * crossref * "}" *
}

FUNCTION {format.incoll.inproc.crossref}
{ editor empty$
  editor field.or.null author field.or.null =
  or
    { key empty$
	{ booktitle empty$
	    { "need editor, key, or booktitle for " cite$ * " to crossref " *
	      crossref * warning$
	      ""
	    }
	    { format.booktitle * }
	  if$
	}
	{ key * }
      if$
    }
    { format.editors * }
  if$
%  " \cite{" * crossref * "}" *
}

FUNCTION {article}
{ "article" bibentry.begin
  "article" biblioset.begin
  format.authors "author" output.check
  format.title "title" output.check
  format.pages output
  format.url output
  format.doi output
  biblioset.end

  "journal" biblioset.begin
  crossref missing$
    { format.jtitle "journal" output.check
      format.vol.num output
      format.date "year" output.check
    }
    { format.article.crossref output.nonnull }
  if$
  biblioset.end
  format.note output
  bibentry.end
}

FUNCTION {book}
{ "book" bibentry.begin
  author empty$
    { format.editors "author and editor" output.check }
    { format.authors output.nonnull
      crossref missing$
	{ "author and editor" editor either.or.check }
	'skip$
      if$
    }
  if$
  format.btitle "title" output.check

  crossref missing$
    { format.bvolume output
      format.number.series output
      format.publisher "publisher" output.check
      format.address output
    }
    { format.book.crossref output.nonnull }
  if$

  format.edition output
  format.date "year" output.check
  format.url output
  format.doi output
  format.note output
  bibentry.end
}

FUNCTION {booklet}
{ "booklet" bibentry.begin
  format.authors output
  format.title "title" output.check
  format.howpublished output
  format.address output
  format.date output
  format.url output
  format.doi output
  format.note output
  bibentry.end
}

FUNCTION {inbook}
{ "inbook" bibentry.begin
  author empty$
    { format.editors "author and editor" output.check }
    { format.authors output.nonnull
      crossref missing$
	{ "author and editor" editor either.or.check }
	'skip$
      if$
    }
  if$
  format.chapter "chapter and pages" output.check
  format.pages output
  format.btitle "title" output.check
  crossref missing$
    { format.bvolume output
      format.number.series output
      format.publisher "publisher" output.check
      format.address output
    }
    { format.book.crossref output.nonnull }
  if$
  format.edition output
  format.date "year" output.check
  format.url output
  format.doi output
  format.note output
  bibentry.end
}

FUNCTION {incollection}
{ "incollection" bibentry.begin

  "chapter" biblioset.begin
  format.authors "author" output.check
  format.title "title" output.check
  format.chapter output
  biblioset.end

  "collection" biblioset.begin
  crossref missing$
    { format.booktitle "booktitle" output.check
      format.editors output
      format.bvolume output
      format.number.series output
      format.publisher "publisher" output.check
      format.address output
      format.edition output
      format.date "year" output.check
    }
    { format.incoll.inproc.crossref output.nonnull }
  if$
  biblioset.end

  format.url output
  format.doi output
  format.note output
  bibentry.end
}

FUNCTION {inproceedings}
{ "inproceedings" bibentry.begin
  "article" biblioset.begin
  format.authors "author" output.check
  format.title "title" output.check
  format.pages output
  format.url output
  format.doi output
  biblioset.end

  "proceedings" biblioset.begin
  crossref missing$
    { format.conf "booktitle" output.check
      format.editors output
      format.bvolume output
      format.number.series output
      format.date "year" output.check
      format.publisher output
    }
    { format.incoll.inproc.crossref output.nonnull }
  if$
  biblioset.end

  format.note output
  bibentry.end
}

FUNCTION {conference} { inproceedings }

FUNCTION {manual}
{ "manual" bibentry.begin
  author empty$
    { organization empty$
	'skip$
	{ format.organization output.nonnull
	  format.address output
	}
      if$
    }
    { format.authors output.nonnull }
  if$
  format.btitle "title" output.check
  author empty$
    { organization empty$
	{ format.address output	}
	'skip$
      if$
    }
    { format.organization output
      format.address output
    }
  if$
  format.edition output
  format.date output
  format.url output
  format.doi output
  format.note output
  bibentry.end
}

FUNCTION {mastersthesis}
{ "mastersthesis" bibentry.begin
  format.authors "author" output.check
  format.title "title" output.check
  "Master's thesis" format.type output.nonnull
  format.school "school" output.check
  format.address output
  format.date "year" output.check
  format.url output
  format.doi output
  format.note output
  bibentry.end
}

FUNCTION {misc}
{ "misc" bibentry.begin
  format.authors output
  format.title output
  format.howpublished output
  format.date output
  format.url output
  format.doi output
  format.note output
  bibentry.end
  empty.misc.check
}

FUNCTION {phdthesis}
{ "phdthesis" bibentry.begin
  format.authors "author" output.check
  format.btitle "title" output.check
  "PhD thesis" format.type output.nonnull
  format.school "school" output.check
  format.address output
  format.date "year" output.check
  format.url output
  format.doi output
  format.note output
  bibentry.end
}

FUNCTION {proceedings}
{ "proceedings" bibentry.begin
  editor empty$
    { format.organization output }
    { format.editors output.nonnull }
  if$
  format.btitle "title" output.check
  format.bvolume output
  format.number.series output
  address empty$
    { editor empty$
	'skip$
	{ format.organization output }
      if$
      format.publisher output
      format.date "year" output.check
    }
    { format.address output.nonnull
      format.date "year" output.check
      editor empty$
	'skip$
	{ format.organization output }
      if$
      format.publisher output
    }
  if$
  format.url output
  format.doi output
  format.note output
  bibentry.end
}

FUNCTION {techreport}
{ "techreport" bibentry.begin
  format.authors "author" output.check
  format.title "title" output.check
  format.tr.number output.nonnull
  format.institution "institution" output.check
  format.address output
  format.date "year" output.check
  format.url output
  format.doi output
  format.note output
  bibentry.end
}

FUNCTION {unpublished}
{ "unpublished" bibentry.begin
  format.authors "author" output.check
  format.title "title" output.check
  format.note "note" output.check
  format.date output
  format.url output
  format.doi output
  bibentry.end
}

FUNCTION {default.type} { misc }

MACRO {jan} {"January"}

MACRO {feb} {"February"}

MACRO {mar} {"March"}

MACRO {apr} {"April"}

MACRO {may} {"May"}

MACRO {jun} {"June"}

MACRO {jul} {"July"}

MACRO {aug} {"August"}

MACRO {sep} {"September"}

MACRO {oct} {"October"}

MACRO {nov} {"November"}

MACRO {dec} {"December"}

MACRO {acmcs} {"ACM Computing Surveys"}

MACRO {acta} {"Acta Informatica"}

MACRO {cacm} {"Communications of the ACM"}

MACRO {ibmjrd} {"IBM Journal of Research and Development"}

MACRO {ibmsj} {"IBM Systems Journal"}

MACRO {ieeese} {"IEEE Transactions on Software Engineering"}

MACRO {ieeetc} {"IEEE Transactions on Computers"}

MACRO {ieeetcad}
 {"IEEE Transactions on Computer-Aided Design of Integrated Circuits"}

MACRO {ipl} {"Information Processing Letters"}

MACRO {jacm} {"Journal of the ACM"}

MACRO {jcss} {"Journal of Computer and System Sciences"}

MACRO {scp} {"Science of Computer Programming"}

MACRO {sicomp} {"SIAM Journal on Computing"}

MACRO {tocs} {"ACM Transactions on Computer Systems"}

MACRO {tods} {"ACM Transactions on Database Systems"}

MACRO {tog} {"ACM Transactions on Graphics"}

MACRO {toms} {"ACM Transactions on Mathematical Software"}

MACRO {toois} {"ACM Transactions on Office Information Systems"}

MACRO {toplas} {"ACM Transactions on Programming Languages and Systems"}

MACRO {tcs} {"Theoretical Computer Science"}

READ

FUNCTION {sortify}
{ purify$
  "l" change.case$
}

INTEGERS { len }

FUNCTION {chop.word}
{ 's :=
  'len :=
  s #1 len substring$ =
    { s len #1 + global.max$ substring$ }
    's
  if$
}

INTEGERS { et.al.char.used }

FUNCTION {initialize.et.al.char.used}
{ #0 'et.al.char.used :=
}

EXECUTE {initialize.et.al.char.used}

FUNCTION {format.lab.names}
{ 's :=
  s num.names$ 'numnames :=
  numnames #1 >
    { numnames #4 >
	{ #3 'namesleft := }
	{ numnames 'namesleft := }
      if$
      #1 'nameptr :=
      ""
	{ namesleft #0 > }
	{ nameptr numnames =
	    { s nameptr "{ff }{vv }{ll}{ jj}" format.name$ "others" =
		{ "{\etalchar{+}}" *
		  #1 'et.al.char.used :=
		}
		{ s nameptr "{v{}}{l{}}" format.name$ * }
	      if$
	    }
	    { s nameptr "{v{}}{l{}}" format.name$ * }
	  if$
	  nameptr #1 + 'nameptr :=
	  namesleft #1 - 'namesleft :=
	}
      while$
      numnames #4 >
	{ "{\etalchar{+}}" *
	  #1 'et.al.char.used :=
	}
	'skip$
      if$
    }
    { s #1 "{v{}}{l{}}" format.name$
      duplicate$ text.length$ #2 <
	{ pop$ s #1 "{ll}" format.name$ #3 text.prefix$ }
	'skip$
      if$
    }
  if$
}

FUNCTION {author.key.label}
{ author empty$
    { key empty$
	{ cite$ #1 #3 substring$ }
	{ key #3 text.prefix$ }
      if$
    }
    { author format.lab.names }
  if$
}

FUNCTION {author.editor.key.label}
{ author empty$
    { editor empty$
	{ key empty$
	    { cite$ #1 #3 substring$ }
	    { key #3 text.prefix$ }
	  if$
	}
	{ editor format.lab.names }
      if$
    }
    { author format.lab.names }
  if$
}

FUNCTION {author.key.organization.label}
{ author empty$
    { key empty$
	{ organization empty$
	    { cite$ #1 #3 substring$ }
	    { "The " #4 organization chop.word #3 text.prefix$ }
	  if$
	}
	{ key #3 text.prefix$ }
      if$
    }
    { author format.lab.names }
  if$
}

FUNCTION {editor.key.organization.label}
{ editor empty$
    { key empty$
	{ organization empty$
	    { cite$ #1 #3 substring$ }
	    { "The " #4 organization chop.word #3 text.prefix$ }
	  if$
	}
	{ key #3 text.prefix$ }
      if$
    }
    { editor format.lab.names }
  if$
}

FUNCTION {calc.label}
{ type$ "book" =
  type$ "inbook" =
  or
    'author.editor.key.label
    { type$ "proceedings" =
	'editor.key.organization.label
	{ type$ "manual" =
	    'author.key.organization.label
	    'author.key.label
	  if$
	}
      if$
    }
  if$
  duplicate$
  year field.or.null purify$ #-1 #2 substring$
  *
  'label :=
  year field.or.null purify$ #-1 #4 substring$
  *
  sortify 'sort.label :=
}

FUNCTION {sort.format.names}
{ 's :=
  #1 'nameptr :=
  ""
  s num.names$ 'numnames :=
  numnames 'namesleft :=
    { namesleft #0 > }
    { nameptr #1 >
	{ "   " * }
	'skip$
      if$
      s nameptr "{vv{ } }{ll{ }}{  ff{ }}{  jj{ }}" format.name$ 't :=
      nameptr numnames = t "others" = and
	{ "et al" * }
	{ t sortify * }
      if$
      nameptr #1 + 'nameptr :=
      namesleft #1 - 'namesleft :=
    }
  while$
}

FUNCTION {sort.format.title}
{ 't :=
  "A " #2
    "An " #3
      "The " #4 t chop.word
    chop.word
  chop.word
  sortify
  #1 global.max$ substring$
}

FUNCTION {author.sort}
{ author empty$
    { key empty$
	{ "to sort, need author or key in " cite$ * warning$
	  ""
	}
	{ key sortify }
      if$
    }
    { author sort.format.names }
  if$
}

FUNCTION {author.editor.sort}
{ author empty$
    { editor empty$
	{ key empty$
	    { "to sort, need author, editor, or key in " cite$ * warning$
	      ""
	    }
	    { key sortify }
	  if$
	}
	{ editor sort.format.names }
      if$
    }
    { author sort.format.names }
  if$
}

FUNCTION {author.organization.sort}
{ author empty$
    { organization empty$
	{ key empty$
	    { "to sort, need author, organization, or key in " cite$ * warning$
	      ""
	    }
	    { key sortify }
	  if$
	}
	{ "The " #4 organization chop.word sortify }
      if$
    }
    { author sort.format.names }
  if$
}

FUNCTION {editor.organization.sort}
{ editor empty$
    { organization empty$
	{ key empty$
	    { "to sort, need editor, organization, or key in " cite$ * warning$
	      ""
	    }
	    { key sortify }
	  if$
	}
	{ "The " #4 organization chop.word sortify }
      if$
    }
    { editor sort.format.names }
  if$
}

FUNCTION {presort}
{ calc.label
  sort.label
  "    "
  *
  type$ "book" =
  type$ "inbook" =
  or
    'author.editor.sort
    { type$ "proceedings" =
	'editor.organization.sort
	{ type$ "manual" =
	    'author.organization.sort
	    'author.sort
	  if$
	}
      if$
    }
  if$
  *
  "    "
  *
  year field.or.null sortify
  *
  "    "
  *
  title field.or.null
  sort.format.title
  *
  #1 entry.max$ substring$
  'sort.key$ :=
}

ITERATE {presort}

SORT

STRINGS { longest.label last.sort.label next.extra }

INTEGERS { longest.label.width last.extra.num }

FUNCTION {initialize.longest.label}
{ "" 'longest.label :=
  #0 int.to.chr$ 'last.sort.label :=
  "" 'next.extra :=
  #0 'longest.label.width :=
  #0 'last.extra.num :=
}

FUNCTION {forward.pass}
{ last.sort.label sort.label =
    { last.extra.num #1 + 'last.extra.num :=
      last.extra.num int.to.chr$ 'extra.label :=
    }
    { "a" chr.to.int$ 'last.extra.num :=
      "" 'extra.label :=
      sort.label 'last.sort.label :=
    }
  if$
}

FUNCTION {reverse.pass}
{ next.extra "b" =
    { "a" 'extra.label := }
    'skip$
  if$
  label extra.label * 'label :=
  label width$ longest.label.width >
    { label 'longest.label :=
      label width$ 'longest.label.width :=
    }
    'skip$
  if$
  extra.label 'next.extra :=
}

EXECUTE {initialize.longest.label}

ITERATE {forward.pass}

REVERSE {reverse.pass}

FUNCTION {begin.bib}
{ "<bibliography>"  write$ newline$
  indent.level #1 + 'indent.level :=
}

EXECUTE {begin.bib}

ITERATE {call.type$}

FUNCTION {end.bib}
{ newline$
  "</bibliography>" write$ newline$
}

EXECUTE {end.bib}
