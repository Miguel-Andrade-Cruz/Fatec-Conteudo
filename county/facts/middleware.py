

def format_acc_chart(qs):

    records_formatted = qs
    for record in qs:
        acc = record["account_code"]
        segm = record["segment_code"]
        niche = record["niche_code"]

        records_formatted["acc_chart"] = f"{acc}.{segm}.{niche}"
    return records_formatted
