struct color{
unsigned char rouge;
unsigned char vert;
unsigned char bleu;
struct color *next;
};


void insertion(struct color*, struct color*);

void parcours(struct color*);
