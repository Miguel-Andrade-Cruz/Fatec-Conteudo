from .models import Account, Chart, Segment


def group_records(qs):

    records_grouped = {}
    for row in qs:

        acc_info = (row["acc__code"], row["acc__label"])
        segm_info = (row["segm__code"], row["segm__label"])

        records_grouped \
            .setdefault(acc_info, {}) \
            .setdefault(segm_info, []) \
            .append(
                (row["niche__code"], row["niche__label"])
            )

    return records_grouped




def pull_accounts():
    ACCOUNTS = {"new": "Criar conta"}

    qs = Account.objects.all().values('code', 'label')
    if not qs.exists():
        return ACCOUNTS

    for record in qs:
        ACCOUNTS.update({record['code']: record['label']})
    return ACCOUNTS


def pull_segments(acc_filter):
    SEGMENTS = {"new": "Criar segmento"}

    if acc_filter["is_new"]:
        return SEGMENTS
    else:
        qs = Chart.objects \
            .select_related('segm') \
            .filter(acc=acc_filter["info"]) \
            .values()

    if not qs.exists():
        return SEGMENTS

    for record in qs:
        SEGMENTS.update({record['code']: record['label']})
    return SEGMENTS


def get_or_new_acc(data):

    if data["prev_accounts"] == "new":
        return (data["new_account"], True)
    else:
        return (data["prev_accounts"], False)

def get_or_new_segm(data):

    if data["prev_segments"] == "new":
        return (data["new_segment"], True)
    else:
        return (data["prev_segments"], False)


# def handle_form_data(data):

#     if data["accounts"] == "new":
#         account = Account(label=data["new_account"])
#         account.save()
#     else:
#         account = Account.objects.get(pk=data["accounts"])

#     if data["segments"] == "new":
#         segment = Segment(label=data["new_segment"])
#         segment.save()
#     else:
#         segment = Segment.objects.get(pk=data["segments"])

#     if data["niches"] == "new":
#         niche = Niche(label=data["new_niche"])
#         niche.save()
#     else:
#         niche = Niche.objects.get(pk=data["niches"])

#     return (account, segment, niche)
