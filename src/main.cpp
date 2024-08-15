/**
Created by Abdulrahman Semrie<hsamireh@gmail.com> on 10/2/20
Copyright © 2020 Abdulrahman Semrie
Annotation Graph is free software; you can redistribute
it and/or modify it under the terms of the GNU General Public
License as published by the Free Software Foundation; either
version 3 of the License, or (at your option) any later version.
This software is distributed in the hope that it will be useful,
but WITHOUT ANY WARRANTY; without even the implied warranty of
MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the GNU
General Public License for more details.
You should have received a copy of the GNU General Public License
along with this software.  If not, see
<http://www.gnu.org/licenses/>.
**/

//

#include "GraphProcessor.h"

using namespace annotation_graph;
int main(int argc, char *argv[]) {
  std::string jsonString = R"(
  {
  "nodes": [
    {
      "data": {
        "id": "ENSG00000149346",
        "type": "gene",
        "gene_name": "SLX4IP",
        "gene_type": "protein_coding",
        "synonyms": "dJ1099D15.3 HGNC:16225 SLX4IP protein_SLX4IP C20orf94 bA254M13.1 SLX4_interacting_protein bA204H22.1",
        "source": "GENCODE",
        "source_url": "https://www.gencodegenes.org/human/",
        "chr": "chr20",
        "start": "10435305",
        "end": "10636829"
      }
    },
    {
      "data": {
        "id": "transcript ENST00000334534",
        "type": "transcript",
        "gene_name": "SLX4IP",
        "transcript_name": "SLX4IP-201",
        "transcript_id": "ENST00000334534.10",
        "transcript_type": "protein_coding",
        "source": "GENCODE",
        "source_url": "https://www.gencodegenes.org/human/",
        "chr": "chr20",
        "start": "10435305",
        "end": "10628030"
      }
    },
    {
      "data": {
        "id": "transcript ENST00000488816",
        "type": "transcript",
        "gene_name": "SLX4IP",
        "transcript_name": "SLX4IP-202",
        "transcript_id": "ENST00000488816.1",
        "transcript_type": "nonsense_mediated_decay",
        "source": "GENCODE",
        "source_url": "https://www.gencodegenes.org/human/",
        "chr": "chr20",
        "start": "10598675",
        "end": "10636829"
      }
    },
    {
      "data": {
        "id": "gene ENSG00000101349",
        "type": "gene",
        "gene_name": "PAK5",
        "gene_type": "protein_coding",
        "synonyms": "p21CDKN1A-activated_kinase_7 PAK7 p21-activated_kinase_5 serine/threonine-protein_kinase_PAK7 PAK-7 serine/threonine-protein_kinase_PAK_7 p21_(RAC1)_activated_kinase_7 p21-activated_kinase_7 p21_protein_(Cdc42/Rac)-activated_kinase_7 protein_kinase_PAK5 serine/threonine-protein_kinase_PAK_5 p21_(RAC1)_activated_kinase_5 p21(CDKN1A)-activated_kinase_7 PAK5 PAK-5 HGNC:15916",
        "source": "GENCODE",
        "source_url": "https://www.gencodegenes.org/human/",
        "chr": "chr20",
        "start": "9537370",
        "end": "9839076"
      }
    },
    {
      "data": {
        "id": "transcript ENST00000353224",
        "type": "transcript",
        "gene_name": "PAK5",
        "transcript_name": "PAK5-201",
        "transcript_id": "ENST00000353224.10",
        "transcript_type": "protein_coding",
        "source": "GENCODE",
        "source_url": "https://www.gencodegenes.org/human/",
        "chr": "chr20",
        "start": "9537370",
        "end": "9839076"
      }
    },
    {
      "data": {
        "id": "transcript ENST00000378423",
        "type": "transcript",
        "gene_name": "PAK5",
        "transcript_name": "PAK5-202",
        "transcript_id": "ENST00000378423.5",
        "transcript_type": "protein_coding",
        "source": "GENCODE",
        "source_url": "https://www.gencodegenes.org/human/",
        "chr": "chr20",
        "start": "9537389",
        "end": "9838831"
      }
    },
    {
      "data": {
        "id": "transcript ENST00000378429",
        "type": "transcript",
        "gene_name": "PAK5",
        "transcript_name": "PAK5-203",
        "transcript_id": "ENST00000378429.3",
        "transcript_type": "protein_coding",
        "source": "GENCODE",
        "source_url": "https://www.gencodegenes.org/human/",
        "chr": "chr20",
        "start": "9537389",
        "end": "9839041"
      }
    },
    {
      "data": {
        "id": "gene ENSG00000285508",
        "type": "gene",
        "gene_name": "MKKS",
        "gene_type": "protein_coding",
        "synonyms": "LOC128706666 uncharacterized_LOC128706666",
        "source": "GENCODE",
        "source_url": "https://www.gencodegenes.org/human/",
        "chr": "chr20",
        "start": "10413520",
        "end": "10431922"
      }
    },
    {
      "data": {
        "id": "transcript ENST00000609375",
        "type": "transcript",
        "gene_name": "MKKS",
        "transcript_name": "MKKS-205",
        "transcript_id": "ENST00000609375.1",
        "transcript_type": "protein_coding",
        "source": "GENCODE",
        "source_url": "https://www.gencodegenes.org/human/",
        "chr": "chr20",
        "start": "10413520",
        "end": "10431922"
      }
    },
    {
      "data": {
        "id": "gene ENSG00000197976",
        "type": "gene",
        "gene_name": "AKAP17A",
        "gene_type": "protein_coding",
        "synonyms": "PRKA17A XE7Y splicing_factor,_arginine/serine-rich_17A AKAP17A CXYorf3 XE7 DXYS155E CCDC133 HGNC:18783 721 A_kinase_(PRKA)_anchor_protein_17A B-lymphocyte_surface_antigen pseudoautosomal_gene_XE7 SFRS17A protein_kinase_A-anchoring_protein_17A A-kinase_anchor_protein_17A A-kinase_anchoring_protein_17A AKAP-17A",
        "source": "GENCODE",
        "source_url": "https://www.gencodegenes.org/human/",
        "chr": "chrX",
        "start": "1591604",
        "end": "1602520"
      }
    },
    {
      "data": {
        "id": "transcript ENST00000381261",
        "type": "transcript",
        "gene_name": "AKAP17A",
        "transcript_name": "AKAP17A-202",
        "transcript_id": "ENST00000381261.8",
        "transcript_type": "protein_coding",
        "source": "GENCODE",
        "source_url": "https://www.gencodegenes.org/human/",
        "chr": "chrX",
        "start": "1591625",
        "end": "1600303"
      }
    },
    {
      "data": {
        "id": "transcript ENST00000474361",
        "type": "transcript",
        "gene_name": "AKAP17A",
        "transcript_name": "AKAP17A-203",
        "transcript_id": "ENST00000474361.6",
        "transcript_type": "nonsense_mediated_decay",
        "source": "GENCODE",
        "source_url": "https://www.gencodegenes.org/human/",
        "chr": "chrX",
        "start": "1591623",
        "end": "1602502"
      }
    },
    {
      "data": {
        "id": "transcript ENST00000313871",
        "type": "transcript",
        "gene_name": "AKAP17A",
        "transcript_name": "AKAP17A-201",
        "transcript_id": "ENST00000313871.9",
        "transcript_type": "protein_coding",
        "source": "GENCODE",
        "source_url": "https://www.gencodegenes.org/human/",
        "chr": "chrX",
        "start": "1591604",
        "end": "1602520"
      }
    },
    {
      "data": {
        "id": "gene ENSG00000285723",
        "type": "gene",
        "gene_name": "MKKS",
        "gene_type": "protein_coding",
        "synonyms": "uncharacterized_LOC128706665 LOC128706665",
        "source": "GENCODE",
        "source_url": "https://www.gencodegenes.org/human/",
        "chr": "chr20",
        "start": "10420546",
        "end": "10420737"
      }
    },
    {
      "data": {
        "id": "transcript ENST00000649912",
        "type": "transcript",
        "gene_name": "MKKS",
        "transcript_name": "MKKS-206",
        "transcript_id": "ENST00000649912.1",
        "transcript_type": "protein_coding",
        "source": "GENCODE",
        "source_url": "https://www.gencodegenes.org/human/",
        "chr": "chr20",
        "start": "10420546",
        "end": "10420737"
      }
    },
    {
      "data": {
        "id": "gene ENSG00000132623",
        "type": "gene",
        "gene_name": "ANKEF1",
        "gene_type": "protein_coding",
        "synonyms": "ANKRD5 ankyrin_repeat_and_EF-hand_domain_containing_1 ANKEF1 ankyrin_repeat_domain-containing_protein_5 HGNC:15803 ankyrin_repeat_and_EF-hand_domain-containing_protein_1",
        "source": "GENCODE",
        "source_url": "https://www.gencodegenes.org/human/",
        "chr": "chr20",
        "start": "9986126",
        "end": "10058303"
      }
    },
    {
      "data": {
        "id": "transcript ENST00000488991",
        "type": "transcript",
        "gene_name": "ANKEF1",
        "transcript_name": "ANKEF1-204",
        "transcript_id": "ENST00000488991.1",
        "transcript_type": "protein_coding_CDS_not_defined",
        "source": "GENCODE",
        "source_url": "https://www.gencodegenes.org/human/",
        "chr": "chr20",
        "start": "10035117",
        "end": "10055827"
      }
    },
    {
      "data": {
        "id": "transcript ENST00000378380",
        "type": "transcript",
        "gene_name": "ANKEF1",
        "transcript_name": "ANKEF1-201",
        "transcript_id": "ENST00000378380.4",
        "transcript_type": "protein_coding",
        "source": "GENCODE",
        "source_url": "https://www.gencodegenes.org/human/",
        "chr": "chr20",
        "start": "10035049",
        "end": "10058303"
      }
    },
    {
      "data": {
        "id": "transcript ENST00000437504",
        "type": "transcript",
        "gene_name": "ANKEF1",
        "transcript_name": "ANKEF1-203",
        "transcript_id": "ENST00000437504.1",
        "transcript_type": "protein_coding_CDS_not_defined",
        "source": "GENCODE",
        "source_url": "https://www.gencodegenes.org/human/",
        "chr": "chr20",
        "start": "9986126",
        "end": "10043216"
      }
    },
    {
      "data": {
        "id": "transcript ENST00000378392",
        "type": "transcript",
        "gene_name": "ANKEF1",
        "transcript_name": "ANKEF1-202",
        "transcript_id": "ENST00000378392.6",
        "transcript_type": "protein_coding",
        "source": "GENCODE",
        "source_url": "https://www.gencodegenes.org/human/",
        "chr": "chr20",
        "start": "10034987",
        "end": "10058303"
      }
    },
    {
      "data": {
        "id": "gene ENSG00000101384",
        "type": "gene",
        "gene_name": "JAG1",
        "gene_type": "protein_coding",
        "synonyms": "DCHE jagged_canonical_Notch_ligand_1 JAGL1 HGNC:6188 AWS protein_jagged-1 AHD CMT2HH HJ1 AGS AGS1 JAG1 CD339",
        "source": "GENCODE",
        "source_url": "https://www.gencodegenes.org/human/",
        "chr": "chr20",
        "start": "10637684",
        "end": "10673999"
      }
    },
    {
      "data": {
        "id": "transcript ENST00000617357",
        "type": "transcript",
        "gene_name": "JAG1",
        "transcript_name": "JAG1-206",
        "transcript_id": "ENST00000617357.1",
        "transcript_type": "retained_intron",
        "source": "GENCODE",
        "source_url": "https://www.gencodegenes.org/human/",
        "chr": "chr20",
        "start": "10639870",
        "end": "10641276"
      }
    },
    {
      "data": {
        "id": "transcript ENST00000254958",
        "type": "transcript",
        "gene_name": "JAG1",
        "transcript_name": "JAG1-201",
        "transcript_id": "ENST00000254958.10",
        "transcript_type": "protein_coding",
        "source": "GENCODE",
        "source_url": "https://www.gencodegenes.org/human/",
        "chr": "chr20",
        "start": "10637684",
        "end": "10673999"
      }
    },
    {
      "data": {
        "id": "transcript ENST00000423891",
        "type": "transcript",
        "gene_name": "JAG1",
        "transcript_name": "JAG1-202",
        "transcript_id": "ENST00000423891.6",
        "transcript_type": "protein_coding_CDS_not_defined",
        "source": "GENCODE",
        "source_url": "https://www.gencodegenes.org/human/",
        "chr": "chr20",
        "start": "10637759",
        "end": "10662506"
      }
    },
    {
      "data": {
        "id": "transcript ENST00000613518",
        "type": "transcript",
        "gene_name": "JAG1",
        "transcript_name": "JAG1-205",
        "transcript_id": "ENST00000613518.1",
        "transcript_type": "protein_coding",
        "source": "GENCODE",
        "source_url": "https://www.gencodegenes.org/human/",
        "chr": "chr20",
        "start": "10645722",
        "end": "10648028"
      }
    },
    {
      "data": {
        "id": "transcript ENST00000620743",
        "type": "transcript",
        "gene_name": "JAG1",
        "transcript_name": "JAG1-208",
        "transcript_id": "ENST00000620743.1",
        "transcript_type": "retained_intron",
        "source": "GENCODE",
        "source_url": "https://www.gencodegenes.org/human/",
        "chr": "chr20",
        "start": "10647981",
        "end": "10649588"
      }
    },
    {
      "data": {
        "id": "transcript ENST00000612857",
        "type": "transcript",
        "gene_name": "JAG1",
        "transcript_name": "JAG1-204",
        "transcript_id": "ENST00000612857.1",
        "transcript_type": "retained_intron",
        "source": "GENCODE",
        "source_url": "https://www.gencodegenes.org/human/",
        "chr": "chr20",
        "start": "10645372",
        "end": "10647312"
      }
    },
    {
      "data": {
        "id": "transcript ENST00000622545",
        "type": "transcript",
        "gene_name": "JAG1",
        "transcript_name": "JAG1-209",
        "transcript_id": "ENST00000622545.1",
        "transcript_type": "nonsense_mediated_decay",
        "source": "GENCODE",
        "source_url": "https://www.gencodegenes.org/human/",
        "chr": "chr20",
        "start": "10647048",
        "end": "10650257"
      }
    },
    {
      "data": {
        "id": "transcript ENST00000488480",
        "type": "transcript",
        "gene_name": "JAG1",
        "transcript_name": "JAG1-203",
        "transcript_id": "ENST00000488480.2",
        "transcript_type": "retained_intron",
        "source": "GENCODE",
        "source_url": "https://www.gencodegenes.org/human/",
        "chr": "chr20",
        "start": "10644443",
        "end": "10646366"
      }
    },
    {
      "data": {
        "id": "transcript ENST00000617965",
        "type": "transcript",
        "gene_name": "JAG1",
        "transcript_name": "JAG1-207",
        "transcript_id": "ENST00000617965.2",
        "transcript_type": "retained_intron",
        "source": "GENCODE",
        "source_url": "https://www.gencodegenes.org/human/",
        "chr": "chr20",
        "start": "10641580",
        "end": "10652722"
      }
    },
    {
      "data": {
        "id": "gene ENSG00000197976_PAR_Y",
        "type": "gene",
        "gene_name": "AKAP17A",
        "gene_type": "protein_coding",
        "synonyms": "PRKA17A XE7Y splicing_factor,_arginine/serine-rich_17A AKAP17A CXYorf3 XE7 DXYS155E CCDC133 HGNC:18783 721 A_kinase_(PRKA)_anchor_protein_17A B-lymphocyte_surface_antigen pseudoautosomal_gene_XE7 SFRS17A protein_kinase_A-anchoring_protein_17A A-kinase_anchor_protein_17A A-kinase_anchoring_protein_17A AKAP-17A",
        "source": "GENCODE",
        "source_url": "https://www.gencodegenes.org/human/",
        "chr": "chrY",
        "start": "1591604",
        "end": "1602520"
      }
    },
    {
      "data": {
        "id": "transcript ENST00000474361_PAR_Y",
        "type": "transcript",
        "gene_name": "AKAP17A",
        "transcript_name": "AKAP17A-203",
        "transcript_id": "ENST00000474361.6_PAR_Y",
        "transcript_type": "nonsense_mediated_decay",
        "source": "GENCODE",
        "source_url": "https://www.gencodegenes.org/human/",
        "chr": "chrY",
        "start": "1591623",
        "end": "1602502"
      }
    },
    {
      "data": {
        "id": "transcript ENST00000381261_PAR_Y",
        "type": "transcript",
        "gene_name": "AKAP17A",
        "transcript_name": "AKAP17A-202",
        "transcript_id": "ENST00000381261.8_PAR_Y",
        "transcript_type": "protein_coding",
        "source": "GENCODE",
        "source_url": "https://www.gencodegenes.org/human/",
        "chr": "chrY",
        "start": "1591625",
        "end": "1600303"
      }
    },
    {
      "data": {
        "id": "transcript ENST00000313871_PAR_Y",
        "type": "transcript",
        "gene_name": "AKAP17A",
        "transcript_name": "AKAP17A-201",
        "transcript_id": "ENST00000313871.9_PAR_Y",
        "transcript_type": "protein_coding",
        "source": "GENCODE",
        "source_url": "https://www.gencodegenes.org/human/",
        "chr": "chrY",
        "start": "1591604",
        "end": "1602520"
      }
    },
    {
      "data": {
        "id": "gene ENSG00000172296",
        "type": "gene",
        "gene_name": "SPTLC3",
        "gene_type": "protein_coding",
        "synonyms": "SPTLC2L HGNC:16253 serine_palmitoyltransferase,_long_chain_base_subunit_2-like_(aminotransferase_2) long_chain_base_biosynthesis_protein_3 serine_palmitoyltransferase_long_chain_base_subunit_3 SPT3 LCB3 dJ718P11 serine_palmitoyltransferase_3 hLCB2b LCB_3 serine-palmitoyl-CoA_transferase_3 C20orf38 long_chain_base_biosynthesis_protein_2b LCB2B SPTLC3 dJ718P11.1 SPT_3",
        "source": "GENCODE",
        "source_url": "https://www.gencodegenes.org/human/",
        "chr": "chr20",
        "start": "13008972",
        "end": "13169103"
      }
    },
    {
      "data": {
        "id": "transcript ENST00000476791",
        "type": "transcript",
        "gene_name": "SPTLC3",
        "transcript_name": "SPTLC3-205",
        "transcript_id": "ENST00000476791.1",
        "transcript_type": "protein_coding_CDS_not_defined",
        "source": "GENCODE",
        "source_url": "https://www.gencodegenes.org/human/",
        "chr": "chr20",
        "start": "13008979",
        "end": "13051018"
      }
    },
    {
      "data": {
        "id": "transcript ENST00000399002",
        "type": "transcript",
        "gene_name": "SPTLC3",
        "transcript_name": "SPTLC3-201",
        "transcript_id": "ENST00000399002.7",
        "transcript_type": "protein_coding",
        "source": "GENCODE",
        "source_url": "https://www.gencodegenes.org/human/",
        "chr": "chr20",
        "start": "13008972",
        "end": "13169103"
      }
    },
    {
      "data": {
        "id": "transcript ENST00000450297",
        "type": "transcript",
        "gene_name": "SPTLC3",
        "transcript_name": "SPTLC3-204",
        "transcript_id": "ENST00000450297.1",
        "transcript_type": "protein_coding",
        "source": "GENCODE",
        "source_url": "https://www.gencodegenes.org/human/",
        "chr": "chr20",
        "start": "13009349",
        "end": "13079867"
      }
    },
    {
      "data": {
        "id": "transcript ENST00000434210",
        "type": "transcript",
        "gene_name": "SPTLC3",
        "transcript_name": "SPTLC3-203",
        "transcript_id": "ENST00000434210.5",
        "transcript_type": "protein_coding",
        "source": "GENCODE",
        "source_url": "https://www.gencodegenes.org/human/",
        "chr": "chr20",
        "start": "13008987",
        "end": "13072371"
      }
    },
    {
      "data": {
        "id": "gene ENSG00000132639",
        "type": "gene",
        "gene_name": "SNAP25",
        "gene_type": "protein_coding",
        "synonyms": "synaptosome_associated_protein_25kDa HGNC:11132 SEC9 SNAP synaptosomal-associated_protein_25 synaptosome_associated_protein_25 resistance_to_inhibitors_of_cholinesterase_4_homolog dJ1068F16.2 RIC4 SNAP-25 synaptosomal-associated_protein,_25kDa SNAP25 bA416N4.2 RIC-4 SUP CMS18",
        "source": "GENCODE",
        "source_url": "https://www.gencodegenes.org/human/",
        "chr": "chr20",
        "start": "10172395",
        "end": "10308258"
      }
    },
    {
      "data": {
        "id": "transcript ENST00000706269",
        "type": "transcript",
        "gene_name": "SNAP25",
        "transcript_name": "SNAP25-223",
        "transcript_id": "ENST00000706269.1",
        "transcript_type": "protein_coding",
        "source": "GENCODE",
        "source_url": "https://www.gencodegenes.org/human/",
        "chr": "chr20",
        "start": "10219159",
        "end": "10307418"
      }
    },
    {
      "data": {
        "id": "transcript ENST00000693325",
        "type": "transcript",
        "gene_name": "SNAP25",
        "transcript_name": "SNAP25-221",
        "transcript_id": "ENST00000693325.1",
        "transcript_type": "protein_coding",
        "source": "GENCODE",
        "source_url": "https://www.gencodegenes.org/human/",
        "chr": "chr20",
        "start": "10218857",
        "end": "10308258"
      }
    },
    {
      "data": {
        "id": "transcript ENST00000492814",
        "type": "transcript",
        "gene_name": "SNAP25",
        "transcript_name": "SNAP25-204",
        "transcript_id": "ENST00000492814.1",
        "transcript_type": "retained_intron",
        "source": "GENCODE",
        "source_url": "https://www.gencodegenes.org/human/",
        "chr": "chr20",
        "start": "10275519",
        "end": "10278069"
      }
    },
    {
      "data": {
        "id": "transcript ENST00000685131",
        "type": "transcript",
        "gene_name": "SNAP25",
        "transcript_name": "SNAP25-206",
        "transcript_id": "ENST00000685131.1",
        "transcript_type": "protein_coding",
        "source": "GENCODE",
        "source_url": "https://www.gencodegenes.org/human/",
        "chr": "chr20",
        "start": "10218881",
        "end": "10308258"
      }
    },
    {
      "data": {
        "id": "transcript ENST00000691353",
        "type": "transcript",
        "gene_name": "SNAP25",
        "transcript_name": "SNAP25-217",
        "transcript_id": "ENST00000691353.1",
        "transcript_type": "protein_coding",
        "source": "GENCODE",
        "source_url": "https://www.gencodegenes.org/human/",
        "chr": "chr20",
        "start": "10219159",
        "end": "10308258"
      }
    },
    {
      "data": {
        "id": "transcript ENST00000687785",
        "type": "transcript",
        "gene_name": "SNAP25",
        "transcript_name": "SNAP25-207",
        "transcript_id": "ENST00000687785.1",
        "transcript_type": "protein_coding",
        "source": "GENCODE",
        "source_url": "https://www.gencodegenes.org/human/",
        "chr": "chr20",
        "start": "10218885",
        "end": "10308258"
      }
    },
    {
      "data": {
        "id": "transcript ENST00000689858",
        "type": "transcript",
        "gene_name": "SNAP25",
        "transcript_name": "SNAP25-212",
        "transcript_id": "ENST00000689858.1",
        "transcript_type": "protein_coding",
        "source": "GENCODE",
        "source_url": "https://www.gencodegenes.org/human/",
        "chr": "chr20",
        "start": "10218867",
        "end": "10308258"
      }
    },
    {
      "data": {
        "id": "transcript ENST00000254976",
        "type": "transcript",
        "gene_name": "SNAP25",
        "transcript_name": "SNAP25-201",
        "transcript_id": "ENST00000254976.7",
        "transcript_type": "protein_coding",
        "source": "GENCODE",
        "source_url": "https://www.gencodegenes.org/human/",
        "chr": "chr20",
        "start": "10218830",
        "end": "10307418"
      }
    },
    {
      "data": {
        "id": "transcript ENST00000689248",
        "type": "transcript",
        "gene_name": "SNAP25",
        "transcript_name": "SNAP25-209",
        "transcript_id": "ENST00000689248.1",
        "transcript_type": "protein_coding_CDS_not_defined",
        "source": "GENCODE",
        "source_url": "https://www.gencodegenes.org/human/",
        "chr": "chr20",
        "start": "10218882",
        "end": "10252582"
      }
    },
    {
      "data": {
        "id": "transcript ENST00000304886",
        "type": "transcript",
        "gene_name": "SNAP25",
        "transcript_name": "SNAP25-202",
        "transcript_id": "ENST00000304886.6",
        "transcript_type": "protein_coding",
        "source": "GENCODE",
        "source_url": "https://www.gencodegenes.org/human/",
        "chr": "chr20",
        "start": "10218833",
        "end": "10307418"
      }
    },
    {
      "data": {
        "id": "transcript ENST00000692697",
        "type": "transcript",
        "gene_name": "SNAP25",
        "transcript_name": "SNAP25-220",
        "transcript_id": "ENST00000692697.1",
        "transcript_type": "retained_intron",
        "source": "GENCODE",
        "source_url": "https://www.gencodegenes.org/human/",
        "chr": "chr20",
        "start": "10282382",
        "end": "10308234"
      }
    },
    {
      "data": {
        "id": "transcript ENST00000430336",
        "type": "transcript",
        "gene_name": "SNAP25",
        "transcript_name": "SNAP25-203",
        "transcript_id": "ENST00000430336.1",
        "transcript_type": "protein_coding",
        "source": "GENCODE",
        "source_url": "https://www.gencodegenes.org/human/",
        "chr": "chr20",
        "start": "10219066",
        "end": "10293278"
      }
    },
    {
      "data": {
        "id": "transcript ENST00000690812",
        "type": "transcript",
        "gene_name": "SNAP25",
        "transcript_name": "SNAP25-215",
        "transcript_id": "ENST00000690812.1",
        "transcript_type": "protein_coding",
        "source": "GENCODE",
        "source_url": "https://www.gencodegenes.org/human/",
        "chr": "chr20",
        "start": "10218928",
        "end": "10308258"
      }
    },
    {
      "data": {
        "id": "transcript ENST00000690099",
        "type": "transcript",
        "gene_name": "SNAP25",
        "transcript_name": "SNAP25-213",
        "transcript_id": "ENST00000690099.1",
        "transcript_type": "retained_intron",
        "source": "GENCODE",
        "source_url": "https://www.gencodegenes.org/human/",
        "chr": "chr20",
        "start": "10172395",
        "end": "10290632"
      }
    },
    {
      "data": {
        "id": "transcript ENST00000692411",
        "type": "transcript",
        "gene_name": "SNAP25",
        "transcript_name": "SNAP25-219",
        "transcript_id": "ENST00000692411.1",
        "transcript_type": "protein_coding",
        "source": "GENCODE",
        "source_url": "https://www.gencodegenes.org/human/",
        "chr": "chr20",
        "start": "10218926",
        "end": "10308258"
      }
    },
    {
      "data": {
        "id": "transcript ENST00000691665",
        "type": "transcript",
        "gene_name": "SNAP25",
        "transcript_name": "SNAP25-218",
        "transcript_id": "ENST00000691665.1",
        "transcript_type": "protein_coding",
        "source": "GENCODE",
        "source_url": "https://www.gencodegenes.org/human/",
        "chr": "chr20",
        "start": "10218830",
        "end": "10308258"
      }
    },
    {
      "data": {
        "id": "transcript ENST00000495883",
        "type": "transcript",
        "gene_name": "SNAP25",
        "transcript_name": "SNAP25-205",
        "transcript_id": "ENST00000495883.1",
        "transcript_type": "retained_intron",
        "source": "GENCODE",
        "source_url": "https://www.gencodegenes.org/human/",
        "chr": "chr20",
        "start": "10296230",
        "end": "10307418"
      }
    },
    {
      "data": {
        "id": "transcript ENST00000689077",
        "type": "transcript",
        "gene_name": "SNAP25",
        "transcript_name": "SNAP25-208",
        "transcript_id": "ENST00000689077.1",
        "transcript_type": "protein_coding_CDS_not_defined",
        "source": "GENCODE",
        "source_url": "https://www.gencodegenes.org/human/",
        "chr": "chr20",
        "start": "10172395",
        "end": "10290601"
      }
    },
    {
      "data": {
        "id": "transcript ENST00000689757",
        "type": "transcript",
        "gene_name": "SNAP25",
        "transcript_name": "SNAP25-211",
        "transcript_id": "ENST00000689757.1",
        "transcript_type": "protein_coding",
        "source": "GENCODE",
        "source_url": "https://www.gencodegenes.org/human/",
        "chr": "chr20",
        "start": "10218874",
        "end": "10308258"
      }
    },
    {
      "data": {
        "id": "transcript ENST00000693732",
        "type": "transcript",
        "gene_name": "SNAP25",
        "transcript_name": "SNAP25-222",
        "transcript_id": "ENST00000693732.1",
        "transcript_type": "protein_coding_CDS_not_defined",
        "source": "GENCODE",
        "source_url": "https://www.gencodegenes.org/human/",
        "chr": "chr20",
        "start": "10172395",
        "end": "10290553"
      }
    },
    {
      "data": {
        "id": "transcript ENST00000689723",
        "type": "transcript",
        "gene_name": "SNAP25",
        "transcript_name": "SNAP25-210",
        "transcript_id": "ENST00000689723.1",
        "transcript_type": "retained_intron",
        "source": "GENCODE",
        "source_url": "https://www.gencodegenes.org/human/",
        "chr": "chr20",
        "start": "10284724",
        "end": "10294761"
      }
    },
    {
      "data": {
        "id": "transcript ENST00000691161",
        "type": "transcript",
        "gene_name": "SNAP25",
        "transcript_name": "SNAP25-216",
        "transcript_id": "ENST00000691161.1",
        "transcript_type": "protein_coding",
        "source": "GENCODE",
        "source_url": "https://www.gencodegenes.org/human/",
        "chr": "chr20",
        "start": "10218910",
        "end": "10308258"
      }
    },
    {
      "data": {
        "id": "transcript ENST00000690766",
        "type": "transcript",
        "gene_name": "SNAP25",
        "transcript_name": "SNAP25-214",
        "transcript_id": "ENST00000690766.1",
        "transcript_type": "retained_intron",
        "source": "GENCODE",
        "source_url": "https://www.gencodegenes.org/human/",
        "chr": "chr20",
        "start": "10172395",
        "end": "10294760"
      }
    },
    {
      "data": {
        "id": "gene ENSG00000125863",
        "type": "gene",
        "gene_name": "MKKS",
        "gene_type": "protein_coding",
        "synonyms": "MKKS_centrosomal_shuttling_protein MKS KMS HMCS HGNC:7108 MKKS molecular_chaperone_MKKS alternative_protein_MKKS Bardet-Biedl_syndrome_6_protein BBS6 McKusick-Kaufman/Bardet-Biedl_syndromes_putative_chaperonin",
        "source": "GENCODE",
        "source_url": "https://www.gencodegenes.org/human/",
        "chr": "chr20",
        "start": "10401009",
        "end": "10434222"
      }
    },
    {
      "data": {
        "id": "transcript ENST00000652676",
        "type": "transcript",
        "gene_name": "MKKS",
        "transcript_name": "MKKS-204",
        "transcript_id": "ENST00000652676.1",
        "transcript_type": "protein_coding_CDS_not_defined",
        "source": "GENCODE",
        "source_url": "https://www.gencodegenes.org/human/",
        "chr": "chr20",
        "start": "10404935",
        "end": "10434198"
      }
    },
    {
      "data": {
        "id": "transcript ENST00000347364",
        "type": "transcript",
        "gene_name": "MKKS",
        "transcript_name": "MKKS-201",
        "transcript_id": "ENST00000347364.7",
        "transcript_type": "protein_coding",
        "source": "GENCODE",
        "source_url": "https://www.gencodegenes.org/human/",
        "chr": "chr20",
        "start": "10401009",
        "end": "10434222"
      }
    },
    {
      "data": {
        "id": "transcript ENST00000651692",
        "type": "transcript",
        "gene_name": "MKKS",
        "transcript_name": "MKKS-203",
        "transcript_id": "ENST00000651692.1",
        "transcript_type": "protein_coding",
        "source": "GENCODE",
        "source_url": "https://www.gencodegenes.org/human/",
        "chr": "chr20",
        "start": "10401621",
        "end": "10434214"
      }
    },
    {
      "data": {
        "id": "transcript ENST00000399054",
        "type": "transcript",
        "gene_name": "MKKS",
        "transcript_name": "MKKS-202",
        "transcript_id": "ENST00000399054.6",
        "transcript_type": "protein_coding",
        "source": "GENCODE",
        "source_url": "https://www.gencodegenes.org/human/",
        "chr": "chr20",
        "start": "10405184",
        "end": "10431922"
      }
    },
    {
      "data": {
        "id": "gene ENSG00000132640",
        "type": "gene",
        "gene_name": "BTBD3",
        "gene_type": "protein_coding",
        "synonyms": "BTB_domain_containing_3 HGNC:15854 BTB/POZ_domain-containing_protein_3 BTB_(POZ)_domain_containing_3 dJ742J24.1 BTBD3",
        "source": "GENCODE",
        "source_url": "https://www.gencodegenes.org/human/",
        "chr": "chr20",
        "start": "11890723",
        "end": "11926609"
      }
    },
    {
      "data": {
        "id": "transcript ENST00000399006",
        "type": "transcript",
        "gene_name": "BTBD3",
        "transcript_name": "BTBD3-203",
        "transcript_id": "ENST00000399006.6",
        "transcript_type": "protein_coding",
        "source": "GENCODE",
        "source_url": "https://www.gencodegenes.org/human/",
        "chr": "chr20",
        "start": "11890817",
        "end": "11926609"
      }
    },
    {
      "data": {
        "id": "transcript ENST00000405977",
        "type": "transcript",
        "gene_name": "BTBD3",
        "transcript_name": "BTBD3-204",
        "transcript_id": "ENST00000405977.5",
        "transcript_type": "protein_coding",
        "source": "GENCODE",
        "source_url": "https://www.gencodegenes.org/human/",
        "chr": "chr20",
        "start": "11890828",
        "end": "11926609"
      }
    },
    {
      "data": {
        "id": "transcript ENST00000378226",
        "type": "transcript",
        "gene_name": "BTBD3",
        "transcript_name": "BTBD3-202",
        "transcript_id": "ENST00000378226.7",
        "transcript_type": "protein_coding",
        "source": "GENCODE",
        "source_url": "https://www.gencodegenes.org/human/",
        "chr": "chr20",
        "start": "11917893",
        "end": "11926595"
      }
    },
    {
      "data": {
        "id": "transcript ENST00000422390",
        "type": "transcript",
        "gene_name": "BTBD3",
        "transcript_name": "BTBD3-205",
        "transcript_id": "ENST00000422390.5",
        "transcript_type": "protein_coding",
        "source": "GENCODE",
        "source_url": "https://www.gencodegenes.org/human/",
        "chr": "chr20",
        "start": "11892493",
        "end": "11922687"
      }
    },
    {
      "data": {
        "id": "transcript ENST00000488503",
        "type": "transcript",
        "gene_name": "BTBD3",
        "transcript_name": "BTBD3-213",
        "transcript_id": "ENST00000488503.5",
        "transcript_type": "protein_coding_CDS_not_defined",
        "source": "GENCODE",
        "source_url": "https://www.gencodegenes.org/human/",
        "chr": "chr20",
        "start": "11919277",
        "end": "11922985"
      }
    },
    {
      "data": {
        "id": "transcript ENST00000473416",
        "type": "transcript",
        "gene_name": "BTBD3",
        "transcript_name": "BTBD3-212",
        "transcript_id": "ENST00000473416.1",
        "transcript_type": "protein_coding_CDS_not_defined",
        "source": "GENCODE",
        "source_url": "https://www.gencodegenes.org/human/",
        "chr": "chr20",
        "start": "11919541",
        "end": "11922889"
      }
    },
    {
      "data": {
        "id": "transcript ENST00000618918",
        "type": "transcript",
        "gene_name": "BTBD3",
        "transcript_name": "BTBD3-215",
        "transcript_id": "ENST00000618918.4",
        "transcript_type": "protein_coding",
        "source": "GENCODE",
        "source_url": "https://www.gencodegenes.org/human/",
        "chr": "chr20",
        "start": "11892493",
        "end": "11926590"
      }
    },
    {
      "data": {
        "id": "transcript ENST00000455911",
        "type": "transcript",
        "gene_name": "BTBD3",
        "transcript_name": "BTBD3-209",
        "transcript_id": "ENST00000455911.5",
        "transcript_type": "protein_coding",
        "source": "GENCODE",
        "source_url": "https://www.gencodegenes.org/human/",
        "chr": "chr20",
        "start": "11918810",
        "end": "11922849"
      }
    },
    {
      "data": {
        "id": "transcript ENST00000473180",
        "type": "transcript",
        "gene_name": "BTBD3",
        "transcript_name": "BTBD3-211",
        "transcript_id": "ENST00000473180.1",
        "transcript_type": "protein_coding_CDS_not_defined",
        "source": "GENCODE",
        "source_url": "https://www.gencodegenes.org/human/",
        "chr": "chr20",
        "start": "11921566",
        "end": "11923130"
      }
    },
    {
      "data": {
        "id": "transcript ENST00000471120",
        "type": "transcript",
        "gene_name": "BTBD3",
        "transcript_name": "BTBD3-210",
        "transcript_id": "ENST00000471120.1",
        "transcript_type": "protein_coding_CDS_not_defined",
        "source": "GENCODE",
        "source_url": "https://www.gencodegenes.org/human/",
        "chr": "chr20",
        "start": "11919277",
        "end": "11923035"
      }
    },
    {
      "data": {
        "id": "transcript ENST00000430557",
        "type": "transcript",
        "gene_name": "BTBD3",
        "transcript_name": "BTBD3-206",
        "transcript_id": "ENST00000430557.1",
        "transcript_type": "protein_coding",
        "source": "GENCODE",
        "source_url": "https://www.gencodegenes.org/human/",
        "chr": "chr20",
        "start": "11918851",
        "end": "11922729"
      }
    },
    {
      "data": {
        "id": "transcript ENST00000449299",
        "type": "transcript",
        "gene_name": "BTBD3",
        "transcript_name": "BTBD3-207",
        "transcript_id": "ENST00000449299.5",
        "transcript_type": "nonsense_mediated_decay",
        "source": "GENCODE",
        "source_url": "https://www.gencodegenes.org/human/",
        "chr": "chr20",
        "start": "11890870",
        "end": "11923010"
      }
    },
    {
      "data": {
        "id": "transcript ENST00000618296",
        "type": "transcript",
        "gene_name": "BTBD3",
        "transcript_name": "BTBD3-214",
        "transcript_id": "ENST00000618296.4",
        "transcript_type": "protein_coding",
        "source": "GENCODE",
        "source_url": "https://www.gencodegenes.org/human/",
        "chr": "chr20",
        "start": "11917865",
        "end": "11926590"
      }
    },
    {
      "data": {
        "id": "transcript ENST00000450368",
        "type": "transcript",
        "gene_name": "BTBD3",
        "transcript_name": "BTBD3-208",
        "transcript_id": "ENST00000450368.1",
        "transcript_type": "protein_coding",
        "source": "GENCODE",
        "source_url": "https://www.gencodegenes.org/human/",
        "chr": "chr20",
        "start": "11891327",
        "end": "11918463"
      }
    },
    {
      "data": {
        "id": "transcript ENST00000254977",
        "type": "transcript",
        "gene_name": "BTBD3",
        "transcript_name": "BTBD3-201",
        "transcript_id": "ENST00000254977.7",
        "transcript_type": "protein_coding",
        "source": "GENCODE",
        "source_url": "https://www.gencodegenes.org/human/",
        "chr": "chr20",
        "start": "11890723",
        "end": "11926609"
      }
    }
  ],
  "edges": []
}
)";
  GraphProcessor processor(jsonString);
  std::string output = processor.processGraph();
  std::cout << output << std::endl;
}
