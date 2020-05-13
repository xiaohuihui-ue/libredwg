#define DWG_TYPE DWG_TYPE_DIMSTYLE
#include "common.c"

void
api_process (dwg_object *obj)
{
  int error, isnew;
  BITCODE_RC flag;
  BITCODE_B flag0;
  BITCODE_TV name;
  BITCODE_RS used;
  BITCODE_B is_xref_ref;
  BITCODE_BS is_xref_resolved;
  BITCODE_B is_xref_dep;
  BITCODE_H xref;

  BITCODE_B DIMTOL;
  BITCODE_B DIMLIM;
  BITCODE_B DIMTIH;
  BITCODE_B DIMTOH;
  BITCODE_B DIMSE1;
  BITCODE_B DIMSE2;
  BITCODE_B DIMALT;
  BITCODE_B DIMTOFL;
  BITCODE_B DIMSAH;
  BITCODE_B DIMTIX;
  BITCODE_B DIMSOXD;
  BITCODE_BS DIMALTD;   /*!< r13-r14 only RC */
  BITCODE_BS DIMZIN;    /*!< r13-r14 only RC */
  BITCODE_B DIMSD1;
  BITCODE_B DIMSD2;
  BITCODE_BS DIMTOLJ;   /*!< r13-r14 only RC */
  BITCODE_BS DIMJUST;   /*!< r13-r14 only RC */
  BITCODE_BS DIMFIT;    /*!< r13-r14 only RC */
  BITCODE_B DIMUPT;
  BITCODE_BS DIMTZIN;   /*!< r13-r14 only RC */
  BITCODE_BS DIMMALTZ;  /*!< r13-r14 only RC */
  BITCODE_BS DIMMALTTZ; /*!< r13-r14 only RC */
  BITCODE_BS DIMTAD;    /*!< r13-r14 only RC */
  BITCODE_BS DIMUNIT;
  BITCODE_BS DIMAUNIT;
  BITCODE_BS DIMDEC;
  BITCODE_BS DIMTDEC;
  BITCODE_BS DIMALTU;
  BITCODE_BS DIMALTTD;
  /* BITCODE_H DIMTXSTY; */
  BITCODE_BD DIMSCALE;
  BITCODE_BD DIMASZ;
  BITCODE_BD DIMEXO;
  BITCODE_BD DIMDLI;
  BITCODE_BD DIMEXE;
  BITCODE_BD DIMRND;
  BITCODE_BD DIMDLE;
  BITCODE_BD DIMTP;
  BITCODE_BD DIMTM;
  BITCODE_BD DIMFXL;
  BITCODE_BD DIMJOGANG;
  BITCODE_BS DIMTFILL;
  BITCODE_CMC DIMTFILLCLR;
  BITCODE_BS DIMAZIN;
  BITCODE_BS DIMARCSYM;
  BITCODE_BD DIMTXT;
  BITCODE_BD DIMCEN;
  BITCODE_BD DIMTSZ;
  BITCODE_BD DIMALTF;
  BITCODE_BD DIMLFAC;
  BITCODE_BD DIMTVP;
  BITCODE_BD DIMTFAC;
  BITCODE_BD DIMGAP;
  BITCODE_T DIMPOST;
  BITCODE_T DIMAPOST;
  BITCODE_T DIMBLK_T;
  BITCODE_T DIMBLK1_T;
  BITCODE_T DIMBLK2_T;
  BITCODE_BD DIMALTRND;
  BITCODE_RS DIMCLRD_N; /* preR13 */
  BITCODE_RS DIMCLRE_N; /* preR13 */
  BITCODE_RS DIMCLRT_N; /* preR13 */
  BITCODE_CMC DIMCLRD;
  BITCODE_CMC DIMCLRE;
  BITCODE_CMC DIMCLRT;
  BITCODE_BS DIMADEC;
  BITCODE_BS DIMFRAC;
  BITCODE_BS DIMLUNIT;
  BITCODE_BS DIMDSEP;
  BITCODE_BS DIMTMOVE;
  BITCODE_BS DIMALTZ;
  BITCODE_BS DIMALTTZ;
  BITCODE_BS DIMATFIT;
  BITCODE_B DIMFXLON;   /*!< r2007+ */
  BITCODE_B  DIMTXTDIRECTION; /*!< r2010+ */
  BITCODE_BD DIMALTMZF; /*!< r2010+ */
  BITCODE_T  DIMALTMZS; /*!< r2010+ */
  BITCODE_BD DIMMZF;    /*!< r2010+ */
  BITCODE_T  DIMMZS;    /*!< r2010+ */
  BITCODE_BSd DIMLWD;
  BITCODE_BSd DIMLWE;
  BITCODE_H DIMTXSTY;
  BITCODE_H DIMLDRBLK;
  BITCODE_H DIMBLK;
  BITCODE_H DIMBLK1;
  BITCODE_H DIMBLK2;
  BITCODE_H DIMLTYPE;
  BITCODE_H DIMLTEX1;
  BITCODE_H DIMLTEX2;
  
  Dwg_Version_Type dwg_version = obj->parent->header.version;
  dwg_obj_dimstyle *_obj = dwg_object_to_DIMSTYLE (obj);

  CHK_ENTITY_TYPE (_obj, DIMSTYLE, flag, RC);
  CHK_ENTITY_TYPE (_obj, DIMSTYLE, flag0, B);
  CHK_ENTITY_UTF8TEXT (_obj, DIMSTYLE, name);
  CHK_ENTITY_TYPE (_obj, DIMSTYLE, used, RS);
  CHK_ENTITY_TYPE (_obj, DIMSTYLE, is_xref_ref, B);
  CHK_ENTITY_TYPE (_obj, DIMSTYLE, is_xref_resolved, BS);
  CHK_ENTITY_TYPE (_obj, DIMSTYLE, is_xref_dep, B);
  CHK_ENTITY_H (_obj, DIMSTYLE, xref);

  CHK_ENTITY_TYPE (_obj, DIMSTYLE, DIMTOL, B);
  CHK_ENTITY_TYPE (_obj, DIMSTYLE, DIMLIM, B);
  CHK_ENTITY_TYPE (_obj, DIMSTYLE, DIMTIH, B);
  CHK_ENTITY_TYPE (_obj, DIMSTYLE, DIMTOH, B);
  CHK_ENTITY_TYPE (_obj, DIMSTYLE, DIMSE1, B);
  CHK_ENTITY_TYPE (_obj, DIMSTYLE, DIMSE2, B);
  CHK_ENTITY_TYPE (_obj, DIMSTYLE, DIMALT, B);
  CHK_ENTITY_TYPE (_obj, DIMSTYLE, DIMTOFL, B);
  CHK_ENTITY_TYPE (_obj, DIMSTYLE, DIMSAH, B);
  CHK_ENTITY_TYPE (_obj, DIMSTYLE, DIMTIX, B);
  CHK_ENTITY_TYPE (_obj, DIMSTYLE, DIMSOXD, B);
  CHK_ENTITY_TYPE (_obj, DIMSTYLE, DIMALTD, BS);   /*!< r13-r14 only RC */
  CHK_ENTITY_TYPE (_obj, DIMSTYLE, DIMZIN, BS);    /*!< r13-r14 only RC */
  CHK_ENTITY_TYPE (_obj, DIMSTYLE, DIMSD1, B);
  CHK_ENTITY_TYPE (_obj, DIMSTYLE, DIMSD2, B);
  CHK_ENTITY_TYPE (_obj, DIMSTYLE, DIMTOLJ, BS);   /*!< r13-r14 only RC */
  CHK_ENTITY_TYPE (_obj, DIMSTYLE, DIMJUST, BS);   /*!< r13-r14 only RC */
  CHK_ENTITY_TYPE (_obj, DIMSTYLE, DIMFIT, BS);    /*!< r13-r14 only RC */
  CHK_ENTITY_TYPE (_obj, DIMSTYLE, DIMUPT, B);
  CHK_ENTITY_TYPE (_obj, DIMSTYLE, DIMTZIN, BS);   /*!< r13-r14 only RC */
  CHK_ENTITY_TYPE (_obj, DIMSTYLE, DIMMALTZ, BS);  /*!< r13-r14 only RC */
  CHK_ENTITY_TYPE (_obj, DIMSTYLE, DIMMALTTZ, BS); /*!< r13-r14 only RC */
  CHK_ENTITY_TYPE (_obj, DIMSTYLE, DIMTAD, BS);    /*!< r13-r14 only RC */
  CHK_ENTITY_TYPE (_obj, DIMSTYLE, DIMUNIT, BS);
  CHK_ENTITY_TYPE (_obj, DIMSTYLE, DIMAUNIT, BS);
  CHK_ENTITY_TYPE (_obj, DIMSTYLE, DIMDEC, BS);
  CHK_ENTITY_TYPE (_obj, DIMSTYLE, DIMTDEC, BS);
  CHK_ENTITY_TYPE (_obj, DIMSTYLE, DIMALTU, BS);
  CHK_ENTITY_TYPE (_obj, DIMSTYLE, DIMALTTD, BS);
  CHK_ENTITY_TYPE (_obj, DIMSTYLE, DIMSCALE, BD);
  CHK_ENTITY_TYPE (_obj, DIMSTYLE, DIMASZ, BD);
  CHK_ENTITY_TYPE (_obj, DIMSTYLE, DIMEXO, BD);
  CHK_ENTITY_TYPE (_obj, DIMSTYLE, DIMDLI, BD);
  CHK_ENTITY_TYPE (_obj, DIMSTYLE, DIMEXE, BD);
  CHK_ENTITY_TYPE (_obj, DIMSTYLE, DIMRND, BD);
  CHK_ENTITY_TYPE (_obj, DIMSTYLE, DIMDLE, BD);
  CHK_ENTITY_TYPE (_obj, DIMSTYLE, DIMTP, BD);
  CHK_ENTITY_TYPE (_obj, DIMSTYLE, DIMTM, BD);
  CHK_ENTITY_TYPE (_obj, DIMSTYLE, DIMFXL, BD);
  CHK_ENTITY_TYPE (_obj, DIMSTYLE, DIMJOGANG, BD);
  CHK_ENTITY_TYPE (_obj, DIMSTYLE, DIMTFILL, BS);
  CHK_ENTITY_CMC (_obj, DIMSTYLE, DIMTFILLCLR);
  CHK_ENTITY_TYPE (_obj, DIMSTYLE, DIMAZIN, BS);
  CHK_ENTITY_TYPE (_obj, DIMSTYLE, DIMARCSYM, BS);
  CHK_ENTITY_TYPE (_obj, DIMSTYLE, DIMTXT, BD);
  CHK_ENTITY_TYPE (_obj, DIMSTYLE, DIMCEN, BD);
  CHK_ENTITY_TYPE (_obj, DIMSTYLE, DIMTSZ, BD);
  CHK_ENTITY_TYPE (_obj, DIMSTYLE, DIMALTF, BD);
  CHK_ENTITY_TYPE (_obj, DIMSTYLE, DIMLFAC, BD);
  CHK_ENTITY_TYPE (_obj, DIMSTYLE, DIMTVP, BD);
  CHK_ENTITY_TYPE (_obj, DIMSTYLE, DIMTFAC, BD);
  CHK_ENTITY_TYPE (_obj, DIMSTYLE, DIMGAP, BD);
  CHK_ENTITY_UTF8TEXT (_obj, DIMSTYLE, DIMPOST);
  CHK_ENTITY_UTF8TEXT (_obj, DIMSTYLE, DIMAPOST);
  CHK_ENTITY_UTF8TEXT (_obj, DIMSTYLE, DIMBLK_T);
  CHK_ENTITY_UTF8TEXT (_obj, DIMSTYLE, DIMBLK1_T);
  CHK_ENTITY_UTF8TEXT (_obj, DIMSTYLE, DIMBLK2_T);
  CHK_ENTITY_TYPE (_obj, DIMSTYLE, DIMALTRND, BD);
  CHK_ENTITY_TYPE (_obj, DIMSTYLE, DIMCLRD_N, RS); /* preR13 */
  CHK_ENTITY_TYPE (_obj, DIMSTYLE, DIMCLRE_N, RS); /* preR13 */
  CHK_ENTITY_TYPE (_obj, DIMSTYLE, DIMCLRT_N, RS); /* preR13 */
  CHK_ENTITY_CMC (_obj, DIMSTYLE, DIMCLRD);
  CHK_ENTITY_CMC (_obj, DIMSTYLE, DIMCLRE);
  CHK_ENTITY_CMC (_obj, DIMSTYLE, DIMCLRT);
  CHK_ENTITY_TYPE (_obj, DIMSTYLE, DIMADEC, BS);
  CHK_ENTITY_TYPE (_obj, DIMSTYLE, DIMFRAC, BS);
  CHK_ENTITY_TYPE (_obj, DIMSTYLE, DIMLUNIT, BS);
  CHK_ENTITY_TYPE (_obj, DIMSTYLE, DIMDSEP, BS);
  CHK_ENTITY_TYPE (_obj, DIMSTYLE, DIMTMOVE, BS);
  CHK_ENTITY_TYPE (_obj, DIMSTYLE, DIMALTZ, BS);
  CHK_ENTITY_TYPE (_obj, DIMSTYLE, DIMALTTZ, BS);
  CHK_ENTITY_TYPE (_obj, DIMSTYLE, DIMATFIT, BS);
  CHK_ENTITY_TYPE (_obj, DIMSTYLE, DIMFXLON, B);   /*!< r2007+ */
  CHK_ENTITY_TYPE (_obj, DIMSTYLE, DIMTXTDIRECTION, B); /*!< r2010+ */
  CHK_ENTITY_TYPE (_obj, DIMSTYLE, DIMALTMZF, BD); /*!< r2010+ */
  CHK_ENTITY_UTF8TEXT (_obj, DIMSTYLE, DIMALTMZS); /*!< r2010+ */
  CHK_ENTITY_TYPE (_obj, DIMSTYLE, DIMMZF, BD);    /*!< r2010+ */
  CHK_ENTITY_UTF8TEXT (_obj, DIMSTYLE, DIMMZS);    /*!< r2010+ */
  CHK_ENTITY_TYPE (_obj, DIMSTYLE, DIMLWD, BSd);
  CHK_ENTITY_TYPE (_obj, DIMSTYLE, DIMLWE, BSd);
  CHK_ENTITY_H (_obj, DIMSTYLE, DIMTXSTY);
  CHK_ENTITY_H (_obj, DIMSTYLE, DIMLDRBLK);
  CHK_ENTITY_H (_obj, DIMSTYLE, DIMBLK);
  CHK_ENTITY_H (_obj, DIMSTYLE, DIMBLK1);
  CHK_ENTITY_H (_obj, DIMSTYLE, DIMBLK2);
  CHK_ENTITY_H (_obj, DIMSTYLE, DIMLTYPE);
  CHK_ENTITY_H (_obj, DIMSTYLE, DIMLTEX1);
  CHK_ENTITY_H (_obj, DIMSTYLE, DIMLTEX2);
}
