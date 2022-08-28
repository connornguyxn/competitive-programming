var tags = [
    [
        '⌛ ',
	'⌛ p',
	'⌛ pr',
	'⌛ pri',
	'⌛ prim',
	'⌛ primo',
	'⌛ primor',
	'⌛ primord',
	'⌛ primordi',
	'⌛ primordia',
	'⌛ primordial',
	'⌛ primordia',
	'⌛ primordi',
	'⌛ primord',
	'⌛ primor',
	'⌛ primo',
	'⌛ prim',
	'⌛ pri',
	'⌛ pr',
	'⌛ p',
	'⌛ ',
    ],
    [
        ' ',
        'f',
        'fa',
        'fat',
        'fata',
        'fatal',
        'fatali',
        'fatality',
        'fatality',
        'fatality',
        'fatality',
        'fatality',
        'atality',
        'tality',
        'ality',
        'lity',
        'ity',
        'ty',
        'y',
        ' ',
    ],
    [
        ' ',
        'N ',
        'N3 ',
        'Ne ',
        'Ne\\ ',
        'Ne\\/ ',
        'Nev ',
        'Nev3 ',
        'Neve ',
        'Neve| ',
        'Neve|2 ',
        'Never| ',
        'Never|_ ',
        'Neverl ',
        'Neverl0 ',
        'Neverlo ',
        'Neverlo5 ',
        'Neverlos ',
        'Neverlos3 ',
        'Neverlose ',
        'Neverlose. ',
        'Neverlose.< ',
        'Neverlose.c< ',
        'Neverlose.cc ',
        'Neverlose.c< ',
        'Neverlose.< ',
        'Neverlose. ',
        'Neverlose ',
        'Neverlos3 ',
        'Neverlos ',
        'Neverlo_ ',
        'Neverlo5 ',
        'Neverlo ',
        'Neverl_ ',
        'Never|0 ',
        'Never| ',
        'Neve|2 ',
        'Neve| ',
        'Neve ',
        'Nev3 ',
        'Nev ',
        'Ne\\/ ',
        'Ne\\ ',
        'Ne ',
        'N3 ',
        'N ',
        ' '
    ],
    [
        ' ',
        'e',
        'ev',
        'ev0',
        'ev0l',
        'ev0l',
        'ev0lv',
        'ev0lve',
        'ev0lve.',
        'ev0lve.x',
        'ev0lve.xy',
        'ev0lve.xyz',
        'ev0lve.xyz',
        'ev0lve.xyz',
        'ev0lve.xyz',
        'ev0lve.xyz',
        'ev0lve.xyz',
        'v0lve.xyz',
        '0lve.xyz',
        'lve.xyz',
        've.xyz',
        'e.xyz',
        '.xyz',
        'xyz',
        'yz',
        'z',
        ' ',
    ],
    [
        'ga            ',
        'gam           ',
        'game          ',
        'games         ',
        'gamese        ',
        'gamesen       ',
        'gamesens      ',
        'gamesense     ',
        '      amesense',
        '       mesense',
        '        esense',
        '         sense',
        '          ense',
        '           nse',
        '            se',
        '              ',
    ],
    [
        'onetap.su',
        'nepat.su o',
        'epat.su on',
        'pat.su one',
        'ap.su onet',
        't.su oneta',
        '.su onetap',
        'su onetap.',
        'u onetap.s',
        'onetap.su',
        ],
    ];


ui.add_checkbox('Enable custom clantag', 'is_enabled');
ui.add_slider('tag', 'tag_slider', 1, tags.length());
ui.add_slider('Speed multiplier', 'speed_slider', 1, 10);

var last_time = 0;
var tag_pos = 0;

function drawtag() {
    var is_enabled = vars.get_int('js.is_enabled');
    if (!is_enabled) {
        return;
    };
    var tag_number = vars.get_int('js.tag_slider');
    var tag = tags[tag_number];
    var speed = vars.get_int('js.speed_slider');
    var current_time = parseInt((global_vars.curtime() * speed));
    if (current_time != last_time) {
        cheat.set_tag('' + tag[tag_pos] + '')
        tag_pos = tag_pos % tag.length() + 1;
    };
    last_time = current_time;
};

register_callback('render', drawtag());